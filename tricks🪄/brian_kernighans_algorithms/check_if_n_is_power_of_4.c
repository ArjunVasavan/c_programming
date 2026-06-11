// @leet start
#include<stdbool.h>
bool isPowerOfFour(int n) {
    return n > 0 &&
        ( n & ( n - 1 ) ) == 0 && /* it belongs to power of 2 */
        ( n & 0x55555555) != 0 ; /* all the 4 power stays at the even position */
}
// @leet end

/* NOTE: Power of 4
 * every number which is power of 4 is exacly 1 bit 
 * and that one single bit is at even position (0,2,4,6..)
 * power of 2 that doesnt belong to power of 4 lands on odd position
 * 0x55555555 is an mask we use to chech if its on even position
 * 0101 0101 0101 0101 0101 0101 0101 0101 => 0x55555555
 * if we and with this mask and its not zero means the single bit is at even position
 */
