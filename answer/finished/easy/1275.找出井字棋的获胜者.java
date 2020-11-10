
/*
 * @lc app=leetcode.cn id=1275 lang=java
 *
 * [1275] 找出井字棋的获胜者
 */

/* Test Case:

[[0,0],[2,0],[1,1],[2,1],[2,2]]
[[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
[[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]
[[0,0],[1,1]]
[[1,2],[2,1],[1,0],[0,0],[0,1],[2,0],[1,1]]

*/

/* Method 1: Bit + Math + Table

    Time: O(n)
    Space: O(1)
*/
// @lc code=start
class Solution {

    private static final int[] win = {7, 56, 448, 73, 146, 292, 273, 84};

    public String tictactoe(int[][] moves) {
        if (moves == null || moves.length < 5) return "Pending";
        
        int a = 0, b = 0;
        for (int i = 0, len = moves.length; i < len; ++i) {
            if ((i & 1) == 1) {
                b ^= 1 << (3 * moves[i][0] + moves[i][1]);
            } else {
                a ^= 1 << (3 * moves[i][0] + moves[i][1]);
            }
        }
        for (int i : win) {
            if ((a & i) == i) return "A";
            if ((b & i) == i) return "B";
        }
        return moves.length == 9 ? "Draw" : "Pending";
    }
}
// @lc code=end

