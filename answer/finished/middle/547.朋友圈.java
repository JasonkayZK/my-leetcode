/*
 * @lc app=leetcode.cn id=547 lang=java
 *
 * [547] 朋友圈
 */

/* Test Case:

[[1,1,0],[1,1,0],[0,0,1]]
[[1,1,0],[1,1,1],[0,1,1]]

*/

/* Method 1: DFS

    Time: O(n ^ 2)
    Space: O(n)
*/
// @lc code=start
class Solution {
    public int findCircleNum(int[][] M) {
        int[] marked = new int[M.length];
        int res = 0;
        for (int i = 0; i < M.length; ++i) {
            if (marked[i] == 0) {
                dfs(M, marked, i);
                res++;
            }
        }
        return res;
    }

    public void dfs(int[][] M, int[] marked, int i) {
        for (int j = 0; j < M.length; j++) {
            if (M[i][j] == 1 && marked[j] == 0) {
                marked[j] = 1;
                dfs(M, marked, j);
            }
        }
    }

}


// @lc code=end

