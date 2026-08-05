#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 10
#define DISPLAY_LINES 17  // Number of lines in our display

/* Shared buffer and indices */
int buffer[MAX_BUFFER_SIZE];
int front_index = 0;  // Points to next item to consume
int rear_index  = 0;  // Points to next empty slot to produce into

/* Semaphores */
sem_t buffer_mutex;     // Protects shared buffer
sem_t full_slots;       // Number of filled slots
sem_t empty_slots;      // Number of empty slots

/* Mutex for printing (to avoid garbled output) */
pthread_mutex_t print_mutex = PTHREAD_MUTEX_INITIALIZER;

/* Flag to track if we've displayed the buffer yet */
int first_display = 1;

/* ================= VISUAL BUFFER DISPLAY ================= */
void display_buffer(const char* action, int item)
{
    pthread_mutex_lock(&print_mutex);
    
    // Move cursor up to overwrite previous display (except first time)
    if (!first_display) {
        // Move cursor up DISPLAY_LINES lines
        for (int i = 0; i < DISPLAY_LINES; i++) {
            printf("\033[A");  // ANSI escape code to move cursor up one line
        }
        printf("\r");  // Return to beginning of line
    }
    first_display = 0;
    
    printf("╔════════════════════════════════════════════════════════════════╗\n");
    printf("║                    PRODUCER-CONSUMER BUFFER                    ║\n");
    printf("╠════════════════════════════════════════════════════════════════╣\n");
    
    // Action
    if(action != NULL) {
        printf("║ Action: %-54s ║\n", action);
    } else {
        printf("║ Action: %-54s ║\n", "");
    }
    printf("╠════════════════════════════════════════════════════════════════╣\n");
    
    // Buffer visualization
    printf("║                           BUFFER                               ║\n");
    printf("║ ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐  ║\n");
    printf("║ │");
    for(int i = 0; i < MAX_BUFFER_SIZE; i++) {
        printf("  %d  │", i);
    }
    printf("  ║\n");
    printf("║ ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤  ║\n");
    printf("║ │");
    
    // Calculate positions
    int count = (rear_index - front_index);
    int front_pos = front_index % MAX_BUFFER_SIZE;
    int rear_pos = rear_index % MAX_BUFFER_SIZE;
    
    for(int i = 0; i < MAX_BUFFER_SIZE; i++) {
        int has_data = 0;
        
        if(count > 0) {
            if(count == MAX_BUFFER_SIZE) {
                // Buffer is full
                has_data = 1;
            } else if(front_pos < rear_pos) {
                // No wrap-around: data from front_pos to rear_pos-1
                has_data = (i >= front_pos && i < rear_pos);
            } else {
                // Wrap-around: data from front_pos to end AND from 0 to rear_pos-1
                has_data = (i >= front_pos || i < rear_pos);
            }
        }
        
        if(has_data) {
            printf(" %3d │", buffer[i]);
        } else {
            printf("     │");
        }
    }
    printf("  ║\n");
    printf("║ └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘  ║\n");
    
    // Indices with arrows
    printf("║   ");
    for(int i = 0; i < MAX_BUFFER_SIZE; i++) {
        if(i == front_pos && i == rear_pos) {
            printf("  ↑↓  ");
        } else if(i == front_pos) {
            printf("  ↑   ");
        } else if(i == rear_pos) {
            printf("  ↓   ");
        } else {
            printf("      ");
        }
    }
    printf(" ║\n");
    
    // Labels
    printf("║   ");
    for(int i = 0; i < MAX_BUFFER_SIZE; i++) {
        if(i == front_pos && i == rear_pos) {
            printf(" F/R  ");
        } else if(i == front_pos) {
            printf("Front ");
        } else if(i == rear_pos) {
            printf("Rear  ");
        } else {
            printf("      ");
        }
    }
    printf(" ║\n");
    
    printf("╠════════════════════════════════════════════════════════════════╣\n");
    
    // Semaphore values
    int empty, full;
    sem_getvalue(&empty_slots, &empty);
    sem_getvalue(&full_slots, &full);
    
    printf("║ front_index = %2d  │  rear_index = %2d                           ║\n", 
           front_index, rear_index);
    printf("║ empty_slots = %2d  │  full_slots = %2d  │  Items in buffer: %2d   ║\n", 
           empty, full, count);
    printf("╚════════════════════════════════════════════════════════════════╝\n");
    
    fflush(stdout);  // Force output to display immediately
    
    pthread_mutex_unlock(&print_mutex);
}

/* ================= PRODUCER THREAD ================= */
void* producer_thread(void* arg)
{
    int item_id;
    for (item_id = 0; item_id < 20; item_id++)  // Produce 20 items
    {
        // Wait for empty space
        sem_wait(&empty_slots);
        
        // Lock buffer
        sem_wait(&buffer_mutex);
        
        // Produce item into the rear position
        int pos = rear_index % MAX_BUFFER_SIZE;
        buffer[pos] = item_id;
        rear_index++;
        
        char action[100];
        sprintf(action, "PRODUCED: %d at position %d", item_id, pos);
        display_buffer(action, item_id);
        
        // Unlock buffer
        sem_post(&buffer_mutex);
        
        // Signal new item available
        sem_post(&full_slots);
        
        sleep(1);
    }
    
    return NULL;
}

/* ================= CONSUMER THREAD ================= */
void* consumer_thread(void* arg)
{
    int consumed_item;
    int count = 0;
    
    while(count < 20)  // Consume 20 items
    {
        // Wait for available item
        sem_wait(&full_slots);
        
        // Lock buffer
        sem_wait(&buffer_mutex);
        
        // Consume item from front position
        int pos = front_index % MAX_BUFFER_SIZE;
        consumed_item = buffer[pos];
        front_index++;
        count++;
        
        char action[100];
        sprintf(action, "CONSUMED: %d from position %d", consumed_item, pos);
        display_buffer(action, consumed_item);
        
        // Unlock buffer
        sem_post(&buffer_mutex);
        
        // Signal empty space available
        sem_post(&empty_slots);
        
        sleep(2);  // Consumer is slower
    }
    
    return NULL;
}

/* ================= MAIN ================= */
int main(void)
{
    pthread_t producer_tid, consumer_tid;
    
    printf("\n");
    printf("╔════════════════════════════════════════════════════════════════╗\n");
    printf("║        PRODUCER-CONSUMER PROBLEM VISUALIZATION                 ║\n");
    printf("╠════════════════════════════════════════════════════════════════╣\n");
    printf("║  Buffer Size: 10                                               ║\n");
    printf("║  Producer: Creates items (1 item/sec)                          ║\n");
    printf("║  Consumer: Consumes items (1 item/2 sec)                       ║\n");
    printf("║                                                                ║\n");
    printf("║  Legend:                                                       ║\n");
    printf("║    ↑ Front = Consumer reads from here                          ║\n");
    printf("║    ↓ Rear  = Producer writes here                              ║\n");
    printf("║    F/R     = Front and Rear at same position                   ║\n");
    printf("╚════════════════════════════════════════════════════════════════╝\n");
    printf("\nStarting simulation in 2 seconds...\n\n");
    
    sleep(2);
    
    // Initialize semaphores
    sem_init(&buffer_mutex, 0, 1);           // Binary semaphore (mutex)
    sem_init(&full_slots, 0, 0);             // Initially 0 items in buffer
    sem_init(&empty_slots, 0, MAX_BUFFER_SIZE); // Initially all slots empty
    
    // Display initial state
    display_buffer("INITIAL STATE (Buffer Empty)", -1);
    sleep(2);
    
    // Create threads
    pthread_create(&producer_tid, NULL, producer_thread, NULL);
    pthread_create(&consumer_tid, NULL, consumer_thread, NULL);
    
    // Wait for threads to complete
    pthread_join(producer_tid, NULL);
    pthread_join(consumer_tid, NULL);
    
    // Cleanup
    sem_destroy(&buffer_mutex);
    sem_destroy(&full_slots);
    sem_destroy(&empty_slots);
    pthread_mutex_destroy(&print_mutex);
    
    printf("\n\n");
    printf("╔════════════════════════════════════════════════════════════════╗\n");
    printf("║                    SIMULATION COMPLETE                         ║\n");
    printf("║  🟢 Producer finished: 20 items produced                       ║\n");
    printf("║  🔴 Consumer finished: 20 items consumed                       ║\n");
    printf("╚════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    
    return 0;
}
