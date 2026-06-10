void xorSwap(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}
/* NOTE: XOR Swap Algorithm
 *
 * Origin: Discovered in the early days of systems programming when
 *         memory was extremely scarce. Swapping two variables normally
 *         requires a third temp variable — XOR swap eliminates that.
 *         Was popular in embedded systems and assembly programming
 *         in the 1970s-80s. Modern compilers now optimize regular swaps
 *         just as well, so this is mostly a classic interview trick today.
 *
 * Key insight: XORing a value with itself always gives 0.
 *              XORing any value with 0 gives back itself.
 *              These two properties let you "store" and "retrieve"
 *              information without a temp variable.
 *
 *   e.g:  a = 0101  (5)     b = 0011  (3)
 *
 *   Step 1: a ^= b  →  a = 0101 ^ 0011 = 0110  (a now holds combined info)
 *   Step 2: b ^= a  →  b = 0011 ^ 0110 = 0101  (b is now original a ✅)
 *   Step 3: a ^= b  →  a = 0110 ^ 0101 = 0011  (a is now original b ✅)
 *
 * Why it works (algebraically):
 *   let a = A, b = B
 *   Step 1: a = A^B,  b = B
 *   Step 2: a = A^B,  b = B^(A^B) = A        (B cancels out)
 *   Step 3: a = (A^B)^A = B,  b = A          (A cancels out)
 *
 * WARNING: Never use xorSwap(a, a) — if a and b point to the
 *          same address, step 1 zeroes it out and both become 0.
 *
 * Time: O(1) — 3 XOR operations, no extra memory
 */
