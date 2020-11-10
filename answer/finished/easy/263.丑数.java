/*
 * @lc app=leetcode.cn id=263 lang=java
 *
 * [263] 丑数
 */

/* Test Case:

-1
0
1
4
51
143
443
6
8
14

*/

/* Method 1: Brute Force 
class Solution {
    public boolean isUgly(int num) {
        if (num <= 0) {return false;}
        boolean changeFlag = false;
        while (true) {
            if (num % 2 == 0) {num /= 2; changeFlag = true;}
            if (num % 3 == 0) {num /= 3; changeFlag = true;}
            if (num % 5 == 0) {num /= 5; changeFlag = true;}
            if (!changeFlag) {break;}
            changeFlag = false;
        }
        return num == 1;
    }
}
*/

/* Method 2: Brute Force [Short ver.] */
class Solution {
    public boolean isUgly(int num) {
        if (num <= 0) {return false;}
        for (int i = 2; i < 6; ++i) {
            while (num % i == 0) {num /= i;}
        }
        return num == 1;
    }
}
