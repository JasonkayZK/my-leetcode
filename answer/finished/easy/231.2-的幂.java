/*
 * @lc app=leetcode.cn id=231 lang=java
 *
 * [231] 2的幂
 */

/* Test Case:

-1
0
1
2
3
4
5
6
1234
443
2333

*/

/* Method 1: Java API 
class Solution {
    public boolean isPowerOfTwo(int n) {
        return n > 0 && Integer.bitCount(n) == 1;
    }
}
*/

/* Method 2: Bit Operation


    Time: O(log(n))
    Space: O(1)

*/
class Solution {
    public boolean isPowerOfTwo(int n) {
        if (n <= 0) {return false;}
        n -= 1;
        while (n != 0) {
            if ((n & 1) == 0) {
                return false;
            }
            n >>>= 1;
        }
        return true;
    }
}

