/*
 * @lc app=leetcode.cn id=367 lang=java
 *
 * [367] 有效的完全平方数
 */

/* Test Case:

-1
0
1
2
3
4
14
16
808201

*/

/* Method 1: Math
class Solution {
    public boolean isPerfectSquare(int num) {
        if (num <= 0) {return false;}
        long r = num;
        while (r * r > num) {
            r = (r + num / r) / 2;
        }
        return r*r == num;
    }
}
 */

/* Method 2: Java API */
class Solution {
    public boolean isPerfectSquare(int num) {
        if (num <= 0) {return false;}
        return Math.abs(Math.rint(Math.sqrt(num)) - Math.sqrt(num)) <= 0.00000001;
    }
}

/* Method 3: Binary Search: Overflow!!!! */
