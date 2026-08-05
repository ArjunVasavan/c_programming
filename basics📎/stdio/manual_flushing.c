#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>    // For sleep() function
#include <stdio_ext.h> // For __fpurge() - Linux specific

/*
 * MANUAL BUFFER FLUSHING - Condition 4 for stdout
 * ================================================
 * 
 * What is fflush() and __fpurge()?
 * ---------------------------------
 * fflush(stdout)  → Standard C function - flushes OUTPUT buffer (writes to screen)
 * __fpurge(stdin) → Linux specific - purges INPUT buffer (clears unread input)
 * 
 * Important Difference:
 * ---------------------
 * - fflush(stdout)  → For OUTPUT - makes buffered output visible immediately
 * - __fpurge(stdin) → For INPUT  - clears leftover input (like extra newlines)
 * 
 * Header Files:
 * -------------
 * #include <stdio.h>      → For fflush()
 * #include <stdio_ext.h>  → For __fpurge() (Linux/GNU extension)
 * 
 * Syntax:
 * -------
 * fflush(stdout);   → Flushes the stdout buffer immediately
 * fflush(NULL);     → Flushes ALL output buffers
 * __fpurge(stdin);  → Purges/clears the stdin input buffer (Linux)
 * 
 * When to use fflush()?
 * ---------------------
 * 1. Progress indicators (loading bars, percentages)
 * 2. Debugging output (want to see output before a crash)
 * 3. Real-time logging without newlines
 * 4. Interactive prompts without \n
 * 5. Before long computations or sleep
 * 6. When you need immediate visual feedback
 * 
 * When to use __fpurge()?
 * -----------------------
 * 1. Clear leftover characters in input buffer
 * 2. Remove extra newlines from previous scanf/getchar
 * 3. Prevent unwanted input from affecting next read
 * 4. Clean input stream before important input operations
 * 
 * Why is it needed?
 * -----------------
 * Without fflush():
 *   - Output without \n stays in buffer
 *   - May not appear until much later
 *   - User might think program is frozen
 *   - Debug messages might not appear before crash
 * 
 * With fflush():
 *   - Output appears IMMEDIATELY on screen
 *   - Clear real-time feedback to user
 *   - Better debugging experience
 *   - Professional-looking progress indicators
 * 
 * Automatic Flush vs Manual Flush:
 * --------------------------------
 * Automatic (no fflush needed):
 *   - When \n is encountered
 *   - Before input operations (scanf, getchar, etc.)
 *   - On normal program termination
 *   - When buffer is full
 * 
 * Manual (fflush required):
 *   - Output without \n that needs immediate display
 *   - Progress indicators on same line
 *   - Real-time status updates
 *   - Before long operations
 */

int main() {
    printf("=== Manual Buffer Flushing with fflush() ===\n\n");
    sleep(1);
    
    // Example 1: Without fflush - output delayed
    printf("1. WITHOUT fflush():\n");
    printf("   Loading");  // No \n, stays in buffer
    sleep(1);
    printf(".");  // Still in buffer
    sleep(1);
    printf(".");  // Still in buffer
    sleep(1);
    printf(".");  // Still in buffer
    sleep(1);
    printf(" Done!\n");  // NOW everything appears at once!
    sleep(2);
    
    // Example 2: With fflush - immediate output
    printf("\n2. WITH fflush():\n");
    printf("   Loading");
    fflush(stdout);  // FORCE flush - appears immediately!
    sleep(1);
    printf(".");
    fflush(stdout);  // Each dot appears one by one
    sleep(1);
    printf(".");
    fflush(stdout);
    sleep(1);
    printf(".");
    fflush(stdout);
    sleep(1);
    printf(" Done!\n");
    sleep(2);
    
    // Example 3: Progress bar with fflush
    printf("\n3. PROGRESS BAR:\n");
    printf("   [");
    fflush(stdout);
    for (int i = 0; i < 20; i++) {
        printf("=");
        fflush(stdout);  // Each '=' appears immediately
        usleep(100000);  // 0.1 second delay
    }
    printf("] 100%%\n");
    sleep(1);
    
    // Example 4: Countdown timer with fflush
    printf("\n4. COUNTDOWN TIMER:\n");
    printf("   Starting in: ");
    fflush(stdout);
    for (int i = 5; i > 0; i--) {
        printf("%d ", i);
        fflush(stdout);  // Number appears immediately
        sleep(1);
    }
    printf("GO!\n");
    sleep(1);
    
    // Example 5: Percentage progress with fflush
    printf("\n5. PERCENTAGE PROGRESS:\n");
    printf("   Processing: ");
    fflush(stdout);
    for (int i = 0; i <= 100; i += 10) {
        printf("%d%% ", i);
        fflush(stdout);  // Each percentage appears immediately
        usleep(300000);  // 0.3 second delay
    }
    printf("Complete!\n");
    sleep(1);
    
    // Example 6: Real-time status updates
    printf("\n6. REAL-TIME STATUS UPDATES:\n");
    
    printf("   [Step 1] Initializing...");
    fflush(stdout);  // Show status immediately
    sleep(1);
    printf(" Done\n");
    
    printf("   [Step 2] Loading data...");
    fflush(stdout);
    sleep(1);
    printf(" Done\n");
    
    printf("   [Step 3] Processing...");
    fflush(stdout);
    sleep(1);
    printf(" Done\n");
    
    printf("   [Step 4] Finalizing...");
    fflush(stdout);
    sleep(1);
    printf(" Done\n");
    
    sleep(1);
    
    // Example 7: Debugging with fflush
    printf("\n7. DEBUGGING EXAMPLE:\n");
    printf("   Before critical operation...");
    fflush(stdout);  // IMPORTANT: Ensure message appears before potential crash
    sleep(1);
    printf(" operation successful!\n");
    
    // Example 8: Using __fpurge() to clear input buffer (Linux specific)
    printf("\n8. INPUT BUFFER PURGING with __fpurge():\n");
    printf("   This demonstrates clearing input buffer\n");
    sleep(1);
    
    char input[50];
    printf("   Enter your name: ");
    fflush(stdout);  // Flush output to show prompt
    fgets(input, sizeof(input), stdin);
    printf("   Hello, %s", input);
    
    // Clear any leftover input in buffer before next operation
    __fpurge(stdin);  // Linux specific - clears input buffer
    printf("   Input buffer cleared with __fpurge(stdin)\n");
    sleep(1);
    
    printf("\n   Press Enter to continue...");
    fflush(stdout);
    __fpurge(stdin);  // Clear any previous input
    getchar();
    printf("   Continued!\n");
    
    printf("\n");
    printf("Key Takeaway:\n");
    printf("-------------\n");
    printf("fflush(stdout)  → Flush OUTPUT buffer (make output visible)\n");
    printf("__fpurge(stdin) → Purge INPUT buffer (clear leftover input)\n");
    printf("\nUse fflush(stdout) for: progress bars, timers, status updates, debugging\n");
    printf("Use __fpurge(stdin) for: cleaning input buffer between operations\n");
    
    return 0;
}
