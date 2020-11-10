/*
 * @lc app=leetcode.cn id=657 lang=java
 *
 * [657] 机器人能否返回原点
 */

/* Test Case:

""
"UD"
"LL"

*/

/* Method 1: Simulation 

    Time: O(n)
    Space: O(n)
*/
class Solution {
    public boolean judgeCircle(String moves) {
        if (moves == null || moves.length() == 0) return true;
        int y = 0, x = 0;
        char[] arr = moves.toUpperCase().toCharArray();
        for (char c : arr) {
            if (c == 'R') x++;
            else if (c == 'L') x--; 
            else if (c == 'U') y++;
            else if (c == 'D') y--;
            else {throw new RuntimeException("Operation invalid!");}
        }

        return x == 0 && y == 0;
    }
}

