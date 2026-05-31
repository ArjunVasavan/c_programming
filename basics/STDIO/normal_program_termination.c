#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // For sleep() function

/*
 * NORMAL PROGRAM TERMINATION - Condition 1 for stdout
 * 
 * What is Normal Program Termination?
 * -----------------------------------
 * Normal program termination occurs when:
 *   1. The main() function executes return statement
 *   2. The program calls exit() function
 *   3. The program reaches the end of main() function
 * 
 * Why is it Important for stdout?
 * --------------------------------
 * When a program terminates normally:
 *   - All output buffers (including stdout) are AUTOMATICALLY FLUSHED
 *   - All open files are automatically closed
 *   - Cleanup functions registered with atexit() are called
 *   - Resources are properly released back to the OS
 * 
 * Exit Codes:
 * -----------
 *   return 0;  or  exit(0);   → Success (no errors)
 *   return 1;  or  exit(1);   → Error/Failure
 *   Non-zero values indicate different types of errors
 * 
 * Abnormal Termination (to avoid):
 * ---------------------------------
 *   - abort() - terminates immediately, buffers NOT flushed
 *   - _exit() - bypasses cleanup, buffers NOT flushed
 *   - Signals (like SIGKILL) - forced termination, buffers NOT flushed
 */

int main() {
    printf("Program is starting...\n");
    sleep(1);  // Pause for 1 second to observe output
    
    printf("Performing some operations...\n");
    sleep(1);  // Pause for 1 second
    
    int sum = 10 + 20;
    printf("Sum: %d\n", sum);
    sleep(1);  // Pause for 1 second
    
    printf("Program is ending normally.\n");
    sleep(1);  // Pause for 1 second before exit
    
    // Normal termination: returns 0 to OS indicating success
    // This ensures all stdout buffers are flushed automatically
    return 0;
}
