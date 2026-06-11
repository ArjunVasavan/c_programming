// @leet start
#include <stdbool.h>
bool isPowerOfSixteen(int n) {
    return n > 0 &&
        ( n & ( n - 1 ) ) == 0 &&        /* it belongs to power of 2 */
        ( n & 0x11111111 ) != 0;          /* all the 16 power stays at positions 0,4,8,12.. */
}
// @leet end
/* NOTE: Power of 16
 * every number which is power of 16 has exactly 1 bit
 * and that one single bit is at every 4th position (0,4,8,12..)
 * powers of 2 that don't belong to power of 16 land on other positions
 * 0x11111111 is the mask we use to check if it's at position 0,4,8,12..
 * 0001 0001 0001 0001 0001 0001 0001 0001 => 0x11111111
 * if we AND with this mask and it's not zero means the single bit is at a valid position
 */


