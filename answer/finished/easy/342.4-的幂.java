/*
 * @lc app=leetcode.cn id=342 lang=java
 *
 * [342] 4的幂
 */

/* Test Case:

-4
-1
0
1
2
3
4
16
5
1435
12345
256

*/

/* Method 1: Math 

    Time: O(1)
    Space: O(1)
*/

class Solution {
    public boolean isPowerOfFour(int num) {
        return Math.abs(Math.log(num) / Math.log(4) - Math.rint(Math.log(num) / Math.log(4))) <= 0.000000001;
    }
}

