int hammingWeight(int n) {
    int count = 0;
    while (n) {
        n &= (n-1);
        count+=1;
    }
   return count; 
}
/* NOTE: Brian Kernighan's Bit Counting Algorithm
 *
 * Origin: Kernighan originally discovered n & (n-1) as a way to
 *         clear the lowest set bit in a number — useful in 1970s
 *         systems programming for manipulating hardware registers
 *         and processing bit flags one at a time without branches.
 *         Bit counting was a later reuse of the same identity.
 *
 * Key insight: n & (n-1) always clears the lowest set bit of n.
 *
 * Why? Subtracting 1 flips the lowest set bit to 0
 *      and all bits below it to 1.
 *      ANDing with n cancels out those flipped bits.
 *
 *   e.g:  n     = 1011 0100
 *         n-1   = 1011 0011
 *         n&n-1 = 1011 0000  <-- lowest set bit cleared
 *
 * So each iteration removes exactly one set bit,
 * and we count how many removals it takes to reach 0.
 * That count == number of 1s in n.
 *
 * Time: O(k) where k = number of set bits (at most 32 iterations)
 */
