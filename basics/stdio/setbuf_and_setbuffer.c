#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>    // For sleep() function

/*
 * BUFFER CONTROL - setbuf() and setbuffer()
 * ==========================================
 * 
 * What are setbuf() and setbuffer()?
 * ----------------------------------
 * These functions allow you to CONTROL the buffering behavior of streams.
 * You can change buffer size, disable buffering, or provide custom buffers.
 * 
 * Function Prototypes:
 * --------------------
 * void setbuf(FILE *stream, char *buf);
 * void setbuffer(FILE *stream, char *buf, size_t size);
 * 
 * setbuf() - Simple Buffer Control:
 * ----------------------------------
 * Syntax: setbuf(stdout, buffer);
 * 
 * Two modes:
 * 1. setbuf(stdout, NULL);    → Unbuffered (immediate output)
 * 2. setbuf(stdout, buffer);  → Uses provided buffer (BUFSIZ size)
 * 
 * setbuffer() - Custom Size Buffer Control:
 * ------------------------------------------
 * Syntax: setbuffer(stdout, buffer, size);
 * 
 * Allows you to specify:
 * 1. Custom buffer size (not limited to BUFSIZ)
 * 2. NULL for unbuffered mode
 * 3. Your own buffer with custom size
 * 
 * Buffering Modes:
 * ----------------
 * 1. FULLY BUFFERED (_IOFBF):
 *    - Output stored in buffer until full
 *    - Most efficient for file I/O
 *    - Default for files
 * 
 * 2. LINE BUFFERED (_IOLBF):
 *    - Output stored until \n encountered
 *    - Default for terminal (stdout)
 *    - Flushes on newline
 * 
 * 3. UNBUFFERED (_IONBF):
 *    - No buffering - immediate output
 *    - Slower but instant visibility
 *    - Default for stderr
 * 
 * When to Use setbuf()/setbuffer():
 * ----------------------------------
 * 1. Real-time logging (unbuffered)
 * 2. Performance optimization (larger buffer)
 * 3. Debugging (unbuffered to see output immediately)
 * 4. Custom buffer management
 * 5. Control over I/O behavior
 * 
 * Important Notes:
 * ----------------
 * - Must call BEFORE any I/O operations on the stream
 * - Buffer must remain valid during entire stream lifetime
 * - Use static or dynamic allocation, NOT local variables
 * - setbuf() uses BUFSIZ, setbuffer() allows custom size
 * - Both are older functions; setvbuf() is more modern
 * 
 * Common Use Cases:
 * -----------------
 * setbuf(stdout, NULL);              → Disable buffering
 * setbuffer(stdout, buf, 1024);      → Use 1KB buffer
 * setbuffer(stdout, NULL, 0);        → Disable buffering
 * setbuffer(stdout, buf, 16384);     → Use 16KB buffer
 */

int main() {
    printf("=== setbuf() and setbuffer() - Buffer Control Demo ===\n\n");
    sleep(1);
    
    printf("Default buffer size (BUFSIZ): %d bytes\n\n", BUFSIZ);
    sleep(1);
    
    // =================================================================
    // Example 1: Default buffered behavior (for comparison)
    // =================================================================
    printf("1. DEFAULT BUFFERED OUTPUT:\n");
    printf("   Writing without newline...");
    sleep(2);  // Output might not appear immediately
    printf(" more text...");
    sleep(2);  // Still might be in buffer
    printf(" final text\n");  // NOW it flushes
    sleep(1);
    
    // =================================================================
    // Example 2: Unbuffered using setbuf(stdout, NULL)
    // =================================================================
    printf("\n2. UNBUFFERED MODE using setbuf(stdout, NULL):\n");
    sleep(1);
    
    // Disable buffering - every character appears immediately
    setbuf(stdout, NULL);
    
    printf("   Writing without newline...");
    sleep(2);  // Should appear IMMEDIATELY (unbuffered)
    printf(" more text...");
    sleep(2);  // Should appear IMMEDIATELY
    printf(" final text");  // Should appear IMMEDIATELY (no \n needed)
    sleep(2);
    printf("\n");
    
    printf("   Notice: Each part appeared immediately!\n");
    sleep(1);
    
    // =================================================================
    // Example 3: Custom buffer using setbuffer() - Small buffer
    // =================================================================
    printf("\n3. SMALL CUSTOM BUFFER using setbuffer() - 64 bytes:\n");
    sleep(1);
    
    // Allocate a small custom buffer
    static char small_buffer[64];
    setbuffer(stdout, small_buffer, sizeof(small_buffer));
    
    printf("   Buffer size: 64 bytes\n");
    printf("   Writing 100 characters without newline:\n   ");
    
    // Write more than buffer size
    for (int i = 0; i < 100; i++) {
        printf("X");
        usleep(50000);  // 0.05 second delay
        // Buffer will auto-flush at 64 bytes!
    }
    printf("\n   Buffer auto-flushed at 64 bytes!\n");
    sleep(1);
    
    // =================================================================
    // Example 4: Large custom buffer using setbuffer()
    // =================================================================
    printf("\n4. LARGE CUSTOM BUFFER using setbuffer() - 16KB:\n");
    sleep(1);
    
    // Allocate a large custom buffer
    static char large_buffer[16384];  // 16KB
    setbuffer(stdout, large_buffer, sizeof(large_buffer));
    
    printf("   Buffer size: 16384 bytes (16KB)\n");
    printf("   Writing text - will stay buffered longer:\n");
    sleep(1);
    
    printf("   Text1");
    sleep(1);
    printf(" Text2");
    sleep(1);
    printf(" Text3");
    sleep(1);
    printf(" Text4");
    sleep(1);
    printf("\n");  // Flush with newline
    
    printf("   Larger buffer = more data before auto-flush\n");
    sleep(1);
    
    // =================================================================
    // Example 5: Comparing buffer sizes
    // =================================================================
    printf("\n5. BUFFER SIZE COMPARISON:\n");
    sleep(1);
    
    // Reset to unbuffered for this demo
    setbuf(stdout, NULL);
    
    printf("   Unbuffered (0 bytes):\n");
    printf("     Pros: Immediate output, great for debugging\n");
    printf("     Cons: Slower performance (many system calls)\n\n");
    sleep(1);
    
    printf("   Small buffer (64-512 bytes):\n");
    printf("     Pros: Quick flush, responsive output\n");
    printf("     Cons: Frequent system calls\n\n");
    sleep(1);
    
    printf("   Default buffer (4KB-8KB):\n");
    printf("     Pros: Good balance of performance and responsiveness\n");
    printf("     Cons: May delay output visibility\n\n");
    sleep(1);
    
    printf("   Large buffer (16KB+):\n");
    printf("     Pros: Best performance, fewer system calls\n");
    printf("     Cons: Delayed output, more memory usage\n\n");
    sleep(1);
    
    // =================================================================
    // Example 6: Real-world use cases
    // =================================================================
    printf("6. REAL-WORLD USE CASES:\n\n");
    sleep(1);
    
    printf("   Debugging:\n");
    printf("     setbuf(stdout, NULL);  // See output immediately\n\n");
    sleep(1);
    
    printf("   Real-time logging:\n");
    printf("     setbuf(stdout, NULL);  // No delay in log messages\n\n");
    sleep(1);
    
    printf("   Performance optimization:\n");
    printf("     static char buf[32768];  // 32KB\n");
    printf("     setbuffer(stdout, buf, 32768);  // Fewer system calls\n\n");
    sleep(1);
    
    printf("   Interactive programs:\n");
    printf("     setbuffer(stdout, buf, 512);  // Small buffer, responsive\n\n");
    sleep(1);
    
    // =================================================================
    // Summary
    // =================================================================
    printf("\nKey Takeaways:\n");
    printf("--------------\n");
    printf("setbuf(stdout, NULL):\n");
    printf("  → Unbuffered mode (immediate output)\n");
    printf("  → Simple, binary choice (buffered or not)\n\n");
    
    printf("setbuffer(stdout, buffer, size):\n");
    printf("  → Custom buffer size control\n");
    printf("  → More flexible than setbuf()\n");
    printf("  → Can specify exact buffer size needed\n\n");
    
    printf("Usage Tips:\n");
    printf("  1. Call BEFORE any I/O operations\n");
    printf("  2. Use static or malloc() for buffers\n");
    printf("  3. Unbuffered = slower but immediate\n");
    printf("  4. Larger buffer = faster but delayed\n");
    printf("  5. Choose based on your needs!\n");
    
    return 0;
}
