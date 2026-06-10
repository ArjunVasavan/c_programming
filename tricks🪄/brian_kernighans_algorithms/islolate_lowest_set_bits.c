int lowestSetBit(int n) {
    return n & (-n);
}
/* NOTE: Isolating the Lowest Set Bit
 *
 * Origin: Kernighan & colleagues discovered that two's complement
 *         negation and AND together can isolate a single bit — used
 *         in systems programming for extracting the least significant
 *         flag from a bitmask. Later became the core operation of
 *         Fenwick Trees (Binary Indexed Trees).
 *
 * Key insight: -n in two's complement flips all bits of n and adds 1.
 *              This causes all bits ABOVE the lowest set bit to flip,
 *              but the lowest set bit and everything below stays mirrored.
 *              ANDing cancels everything except that one bit.
 *
 *   e.g:  n    =  1011 0100
 *        -n    =  0100 1100   (flip all bits → 0100 1011, then +1)
 *        n&-n  =  0000 0100   <-- only lowest set bit remains
 *
 * Breakdown:
 *   - Bits ABOVE lowest set bit  → flipped by negation, cancelled by AND
 *   - Lowest set bit             → 1 & 1 = 1 ✅ survives
 *   - Bits BELOW lowest set bit  → were 0 in n, stay 0 in AND
 *
 * Time: O(1) — single CPU instruction on most architectures
 */
