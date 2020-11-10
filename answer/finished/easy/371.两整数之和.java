/*
 * @lc app=leetcode.cn id=371 lang=java
 *
 * 
 * [371] 两整数之和
 */

/* Method 1: Bit Operation [Iterative]
class Solution {
    public int getSum(int a, int b) {
        if (a == 0) {return b;}
        if (b == 0) {return a;}

        while (b != 0) {
            int carry = a & b;
            a = a ^ b;
            b = carry << 1;
        }
        return a;
    }
}
*/

/* Method 2: Bit Operation [Recursive] */
class Solution {
    public int getSum(int a, int b) {
        return (b == 0) ? a : getSum(a ^ b, (a & b) << 1);
    }
}

