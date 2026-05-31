#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // For sleep() function
/*
 * BUFFER FLUSH WITH NEWLINE (\n) - Condition 2 for stdout
 * 
 * What is Line Buffering?
 * -----------------------
 * stdout is LINE BUFFERED when connected to a terminal (interactive mode)
 * This means output is held in a buffer until a NEWLINE character (\n) is encountered
 * 
 * How does \n trigger buffer flush?
 * ----------------------------------
 * When stdout encounters \n:
 *   1. All accumulated data in the buffer is written to the screen
 *   2. The newline itself is also written
 *   3. The cursor moves to the next line
 * 
 * Without \n:
 * -----------
 * - Output stays in the buffer (not visible on screen)
 * - May appear only when buffer is full or program terminates
 * - Can cause confusion during debugging
 * 
 * Key Points:
 * -----------
 * - printf("Hello");        → Stays in buffer (no immediate output)
 * - printf("Hello\n");      → Flushes immediately (output visible)
 * - printf("Line 1\nLine 2\n"); → Both lines flush immediately
 * - Multiple printf() calls without \n accumulate in buffer
 */

int main() {
    printf("=== Demonstrating Buffer Flush with Newline ===\n\n");
    sleep(1);
    
    // Example 1: With newline - immediate flush
    printf("1. WITH NEWLINE: This will appear immediately\n");
    sleep(2);  // Wait 2 seconds - you'll see the output before this delay
    
    // Example 2: Without newline - stays in buffer
    printf("2. WITHOUT NEWLINE: This will wait");  // No \n - stays in buffer
    sleep(2);  // Output may not appear until later
    printf(" ...and appears after delay\n");  // Now it flushes with \n
    sleep(1);
    
    // Example 3: Multiple outputs without newline
    printf("3. ACCUMULATED: ");
    sleep(1);
    printf("Word1 ");
    sleep(1);
    printf("Word2 ");
    sleep(1);
    printf("Word3");  // All stay in buffer
    sleep(1);
    printf("\n");  // NOW everything flushes at once!
    sleep(1);
    
    // Example 4: Multiple newlines - each flushes separately
    printf("4. MULTIPLE NEWLINES:\n");
    sleep(1);
    printf("   Line A\n");  // Flushes immediately
    sleep(1);
    printf("   Line B\n");  // Flushes immediately
    sleep(1);
    printf("   Line C\n");  // Flushes immediately
    sleep(1);
    
    printf("\nProgram ending - all buffers flushed!\n");
    
    return 0;
}
