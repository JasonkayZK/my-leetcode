/*
 * @lc app=leetcode.cn id=892 lang=java
 *
 * [892] 三维形体的表面积
 */

/* Test Case:

[[2]]
[[1,2],[3,4]]
[[1,0],[0,2]]
[[1,1,1],[1,0,1],[1,1,1]]
[[2,2,2],[2,1,2],[2,2,2]]

*/

/* Method 1: Math

    Time: O(n)
    Space: O(1), n = count(grid)
*/
// @lc code=start
class Solution {
    public int surfaceArea(int[][] grid) {
        int res = 0;
        for (int i = 0; i < grid.length; ++i) {
            for (int j = 0; j < grid[0].length; ++j) {
                res += grid[i][j] > 0 ? grid[i][j] * 4 + 2 : 0;
                if (i - 1 >= 0 && grid[i - 1][j] > 0) res -= Math.min(grid[i][j], grid[i - 1][j]);
                if (i + 1 < grid.length && grid[i + 1][j] > 0) res -= Math.min(grid[i][j], grid[i + 1][j]);
                if (j - 1 >= 0 && grid[i][j - 1] > 0) res -= Math.min(grid[i][j], grid[i][j - 1]);
                if (j + 1 < grid[0].length && grid[i][j + 1] > 0) res -= Math.min(grid[i][j], grid[i][j + 1]);
            }
        }
        return res;
    }
}
// @lc code=end

