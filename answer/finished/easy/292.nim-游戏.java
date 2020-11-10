/*
 * @lc app=leetcode.cn id=292 lang=java
 *
 * [292] Nim 游戏
 */

/* Test Case:

1
2
3
4
17
11

*/

class Solution {
    public boolean canWinNim(int n) {
        if (n <= 0) {throw new RuntimeException("n >= 0");}
        return n % 4 != 0;
    }
}

