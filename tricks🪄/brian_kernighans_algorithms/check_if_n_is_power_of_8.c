
// @leet start
#include <stdbool.h>
bool isPowerOfEight(int n) {
    return n > 0 &&
        ( n & ( n - 1 ) ) == 0 &&        /* it belongs to power of 2 */
        ( n & 0x49249249 ) != 0;          /* all the 8 power stays at positions 0,3,6,9.. */
}
// @leet end
/* NOTE: Power of 8
 * every number which is power of 8 has exactly 1 bit
 * and that one single bit is at every 3rd position (0,3,6,9..)
 * powers of 2 that don't belong to power of 8 land on other positions
 * 0x49249249 is the mask we use to check if it's at position 0,3,6,9..
 * 0100 1001 0010 0100 1001 0010 0100 1001 => 0x49249249
 * if we AND with this mask and it's not zero means the single bit is at a valid position
 */
