/*
 * @lc app=leetcode.cn id=190 lang=java
 *
 * [190] 颠倒二进制位
 */

/* Test Case:

00000000000000000000000000000000
00000010100101000001111010011100
11111111111111111111111111111101
11111111111111111111111111111111
10000000000000000000000000000000
00000000000000000000000000000001

*/

/* Method 1: Bit Operation 

    Time: O(log(n))
    Space: O(1)

*/

class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int result = 0, moveCount = 1;
        while (n != 0) {
            result <<= 1;
            result |= (n & 1);
            n >>>= 1;
            moveCount++;
        }
        while (moveCount <= 32) {result <<= 1; moveCount++;}
        return result;
    }
}

