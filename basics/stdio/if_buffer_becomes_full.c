#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>    // For sleep() function
#include <string.h>    // For strlen()

/*
 * BUFFER FULL - AUTOMATIC FLUSH - Condition 5 for stdout
 * =======================================================
 * 
 * What is Buffer Size?
 * --------------------
 * The stdout buffer has a FIXED SIZE (typically 4KB to 8KB on most systems)
 * When the buffer becomes FULL, it automatically flushes to make room for more data.
 * 
 * Buffer Size Details:
 * --------------------
 * - Typical buffer size: 4096 bytes (4KB) or 8192 bytes (8KB)
 * - Varies by system and C library implementation
 * - Can be checked using: BUFSIZ constant (defined in stdio.h)
 * - Linux/Unix: Usually 8192 bytes
 * - Windows: Usually 4096 bytes
 * 
 * How Buffer Full Works:
 * ----------------------
 * 1. Program writes output using printf()
 * 2. Data accumulates in buffer (no \n, no fflush, no input)
 * 3. When buffer reaches capacity → AUTOMATIC FLUSH occurs
 * 4. Buffer is emptied and ready for more data
 * 5. Process continues
 * 
 * When Does This Happen?
 * ----------------------
 * - Printing large amounts of text without \n
 * - Long loops with output but no newlines
 * - Reading and displaying large files
 * - Processing large data without line breaks
 * - String concatenation in output
 * 
 * Why This Matters:
 * -----------------
 * - Prevents buffer overflow
 * - Ensures output eventually appears
 * - Automatic memory management
 * - No manual intervention needed
 * - System handles it efficiently
 * 
 * Comparison of All Flush Conditions:
 * -----------------------------------
 * 1. Normal termination   → Flushes on program exit
 * 2. Newline (\n)        → Flushes when \n encountered
 * 3. Input operation     → Flushes before scanf/getchar
 * 4. Manual fflush()     → Flushes when explicitly called
 * 5. Buffer full         → Flushes when buffer capacity reached
 * 
 * Testing Buffer Full:
 * --------------------
 * We need to write BUFSIZ or more characters without:
 * - Any \n (newline)
 * - Any fflush()
 * - Any input operations
 * Then we'll see the automatic flush happen!
 */

int main() {
    printf("=== Buffer Full - Automatic Flush Demo ===\n\n");
    sleep(1);
    
    // Display buffer size on this system
    printf("System Information:\n");
    printf("  BUFSIZ (buffer size): %d bytes\n", BUFSIZ);
    printf("  We'll fill the buffer to demonstrate auto-flush\n\n");
    sleep(2);
    
    // Example 1: Small output - stays in buffer
    printf("1. SMALL OUTPUT (stays in buffer):\n");
    printf("   Writing short text without newline...");
    sleep(2);  // Notice: text might not appear yet (in buffer)
    printf(" Still no newline");
    sleep(2);  // Still might not appear
    printf("\n");  // NOW it flushes with newline
    sleep(1);
    
    // Example 2: Fill buffer to trigger automatic flush
    printf("\n2. FILLING BUFFER (automatic flush when full):\n");
    printf("   Writing %d characters without newline to fill buffer...\n", BUFSIZ);
    sleep(1);
    printf("   Watch for the automatic flush!\n\n");
    sleep(1);
    
    printf("   Starting... ");
    fflush(stdout);  // Show this initial message
    sleep(1);
    
    // Write exactly BUFSIZ characters without any \n or fflush
    // This will trigger automatic flush when buffer is full
    for (int i = 0; i < BUFSIZ; i++) {
        printf("X");  // No \n, no fflush - just accumulating
        // When buffer fills up, automatic flush will occur!
    }
    
    printf("\n\n   Buffer was automatically flushed when it became full!\n");
    sleep(2);
    
    // Example 3: Demonstrating with text chunks
    printf("\n3. ACCUMULATING TEXT CHUNKS:\n");
    printf("   Adding text piece by piece without newlines...\n");
    sleep(1);
    
    // Clear demonstration with visible text
    printf("   [");
    int chunk_size = BUFSIZ / 20;  // Divide buffer into 20 parts
    for (int i = 0; i < 20; i++) {
        // Write chunk_size characters
        for (int j = 0; j < chunk_size; j++) {
            printf("=");  // No \n, accumulating in buffer
        }
        // After enough chunks, buffer will auto-flush
        usleep(50000);  // 0.05 second delay
    }
    printf("]\n");
    sleep(1);
    
    // Example 4: Large string output
    printf("\n4. LARGE STRING OUTPUT:\n");
    printf("   Creating a large string to exceed buffer size...\n");
    sleep(1);
    
    // Create a string larger than buffer
    char large_text[BUFSIZ * 2];
    for (int i = 0; i < BUFSIZ * 2 - 1; i++) {
        large_text[i] = 'A' + (i % 26);  // A-Z pattern
    }
    large_text[BUFSIZ * 2 - 1] = '\0';
    
    printf("   Writing %ld characters...\n", strlen(large_text));
    printf("   %s", large_text);  // No \n - but will auto-flush when buffer fills
    printf("\n   Done! Buffer flushed automatically during the large output.\n");
    sleep(2);
    
    // Example 5: Demonstrating buffer behavior with counter
    printf("\n5. COUNTING BYTES WRITTEN:\n");
    printf("   Writing and counting until buffer flush...\n");
    sleep(1);
    
    int bytes_written = 0;
    printf("   Bytes: ");
    fflush(stdout);
    
    // Write characters and count
    for (int i = 0; i < BUFSIZ + 100; i++) {
        printf("#");
        bytes_written++;
        
        // At BUFSIZ, automatic flush should occur
        if (bytes_written == BUFSIZ) {
            usleep(500000);  // Pause to observe the flush
        }
    }
    printf("\n   Total bytes written: %d\n", bytes_written);
    printf("   Buffer auto-flushed around %d bytes mark!\n", BUFSIZ);
    sleep(1);
    
    printf("\n");
    printf("Key Takeaways:\n");
    printf("--------------\n");
    printf("1. Buffer size is typically %d bytes (BUFSIZ)\n", BUFSIZ);
    printf("2. When buffer becomes FULL, automatic flush occurs\n");
    printf("3. This happens even without \\n, fflush(), or input operations\n");
    printf("4. System manages this automatically for memory efficiency\n");
    printf("5. Important for processing large outputs without line breaks\n");
    
    printf("\nAll 5 stdout conditions covered:\n");
    printf("  ✓ 1. Normal program termination\n");
    printf("  ✓ 2. Buffer contains \\n (newline)\n");
    printf("  ✓ 3. Program waits for input (scanf, getchar, etc.)\n");
    printf("  ✓ 4. Manual fflush() call\n");
    printf("  ✓ 5. Buffer becomes full (automatic flush)\n");
    
    return 0;
}
