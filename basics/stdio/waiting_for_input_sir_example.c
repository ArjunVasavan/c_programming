#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // For sleep() function

/*
 * LOOP WITH INPUT - Buffer Flush Demonstration
 * =============================================
 * 
 * This example demonstrates buffer flushing in a loop with user input.
 * 
 * Program Flow:
 * -------------
 * 1. Initialize: ch = 'y', i = 10
 * 2. Loop runs while i is greater than 0 (10 iterations)
 * 3. In each iteration:
 *    - Decrement i first (post-decrement: use value, then decrease)
 *    - Print "Hello" with current counter and character
 *    - Wait for user to enter a character
 *    - Sleep for 1 second to observe the flow
 * 
 * Key Observation - Buffer Flushing:
 * ----------------------------------
 * Notice: printf("Hello%d -> %c : ", i, ch);  ← NO \n at the end!
 * 
 * Question: How does the prompt appear on screen without \n?
 * Answer: scanf() AUTOMATICALLY FLUSHES the stdout buffer before reading input!
 * 
 * What happens step-by-step in each iteration:
 * ---------------------------------------------
 * Step 1: printf() writes message to stdout buffer (not visible yet)
 * Step 2: scanf() is encountered
 * Step 3: scanf() FLUSHES the buffer (now message becomes visible)
 * Step 4: scanf() waits for user input (user can see the prompt)
 * Step 5: User types a character and presses Enter
 * Step 6: scanf() reads the character into variable 'ch'
 * Step 7: sleep(1) pauses for 1 second
 * Step 8: Loop continues with decremented counter
 * 
 * Comparison - What if there was NO scanf()?
 * -------------------------------------------
 * Without scanf():
 *   - All 10 "Hello" messages would stay in buffer
 *   - Nothing would appear on screen during the loop
 *   - All output would appear at once when:
 *     * A \n is encountered, OR
 *     * Buffer becomes full, OR
 *     * Program terminates
 * 
 * With scanf():
 *   - Each "Hello" message appears immediately
 *   - User can interact with the program
 *   - Clear, interactive user experience
 * 
 * Why the space in scanf(" %c", &ch)?
 * ------------------------------------
 * The space before %c tells scanf to skip any whitespace characters
 * (including newline from previous Enter key press).
 * Without it, scanf would read the leftover newline instead of waiting
 * for new input.
 */

int main() {
    printf("=== Loop with Input - Buffer Flush Demo ===\n\n");
    sleep(1);
    
    // Initialize variables
    char ch = 'y';  // Starting character
    int i = 10;     // Loop counter (10 iterations)
    
    printf("Instructions:\n");
    printf("  - You will be prompted 10 times\n");
    printf("  - Enter any character each time\n");
    printf("  - Observe how the prompt appears WITHOUT \\n\n");
    printf("  - This happens because scanf() flushes the buffer!\n\n");
    sleep(2);
    
    printf("Starting loop...\n\n");
    sleep(1);
    
    // Main loop - runs 10 times
    while (i--) {
        // Print prompt without \n - but it will still appear!
        // Why? Because scanf() below will flush the buffer automatically
        printf("Hello%d -> %c : ", i, ch);
        
        // scanf() triggers automatic buffer flush
        // Now user can see the prompt and enter input
        scanf(" %c", &ch);  // Space before %c skips whitespace
        
        // Pause to observe the flow clearly
        sleep(1);
    }
    
    printf("\nLoop completed successfully!\n");
    printf("Final character entered was: %c\n", ch);
    printf("\nConclusion: scanf() automatically flushes stdout buffer\n");
    printf("before waiting for input, even without \\n in printf!\n");
    
    return 0;
}
