#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // For sleep() function

/*
 * BUFFER FLUSH BEFORE INPUT - Condition 3 for stdout
 * 
 * What happens when program waits for input?
 * -------------------------------------------
 * When the program encounters an INPUT function like scanf(), getchar(), fgets():
 *   - stdout buffer is AUTOMATICALLY FLUSHED before reading input
 *   - This ensures all prompts/messages are visible to the user
 *   - User can see what they need to enter
 * 
 * Why is this important?
 * ----------------------
 * Without automatic flush before input:
 *   - User wouldn't see the prompt asking for input
 *   - Program would appear frozen or hung
 *   - User wouldn't know what to type
 * 
 * Input Functions that trigger flush:
 * -----------------------------------
 *   - scanf()     → Reads formatted input
 *   - getchar()   → Reads a single character
 *   - gets()      → Reads a line (deprecated, unsafe)
 *   - fgets()     → Reads a line safely
 *   - getc()      → Reads a character from stream
 * 
 * Key Behavior:
 * -------------
 * printf("Enter name: ");  // No \n at end
 * scanf("%s", name);       // Automatically flushes "Enter name: " prompt
 * 
 * The prompt appears BEFORE scanf() waits, even without \n!
 */

int main() {
    char name[50];
    int age;
    char choice;
    
    printf("=== Demonstrating Buffer Flush Before Input ===\n\n");
    sleep(1);
    
    // Example 1: Prompt without newline - still appears before input
    printf("1. Enter your name: ");  // No \n, but will flush before scanf()
    scanf("%s", name);
    printf("   Hello, %s!\n\n", name);
    sleep(1);
    
    // Example 2: Multiple prompts without newline
    printf("2. Enter your age: ");  // No \n
    scanf("%d", &age);
    printf("   You are %d years old!\n\n", age);
    sleep(1);
    
    // Example 3: Using getchar() - also triggers flush
    printf("3. Press any key to continue...");  // No \n
    getchar();  // Clears the newline from previous scanf
    getchar();  // Waits for user input - flushes the prompt first
    printf(" Continued!\n\n");
    sleep(1);
    
    // Example 4: Accumulated output before input
    printf("4. Starting quiz...");
    sleep(1);
    printf(" Question ready...");
    sleep(1);
    printf(" Answer (y/n): ");  // All accumulated text flushes here
    scanf(" %c", &choice);
    printf("   You chose: %c\n\n", choice);
    sleep(1);
    
    // Example 5: Demonstrating the difference
    printf("5. WITHOUT INPUT - this text");
    sleep(2);
    printf(" accumulates in buffer");
    sleep(2);
    printf(" and may not show until...\n");  // ...we add newline
    sleep(1);
    
    printf("\n   But WITH INPUT: Enter anything: ");
    scanf("%s", name);  // This flushes immediately!
    printf("   Input received!\n");
    
    printf("\nProgram ending normally!\n");
    
    return 0;
}
