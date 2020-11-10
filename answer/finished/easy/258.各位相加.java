/*
 * @lc app=leetcode.cn id=258 lang=java
 *
 * [258] 各位相加
 */

/* Test Case:

0
1
2
3
4
5
38
124
4325

*/

/* Method 1: Brute Force: [Recursive] 

class Solution {
    public int addDigits(int num) {
        if (num < 0) {throw new RuntimeException("num >= 0");}
        if (num < 10) {return num;}
        return addDigits(num / 10 + num % 10);
    }

}
*/

/* Method 2: Math */
class Solution {
    public int addDigits(int num) {
        return num == 0 ? 0 : (num % 9 == 0 ? 9 : (num % 9));
    }

}


