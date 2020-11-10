/*
 * @lc app=leetcode.cn id=5230 lang=java
 *
 * [5230] 缀点成线
 */

/* Test Case:

[[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
[[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
[[-3,-2],[-1,-2],[2,-2],[-2,-2],[0,-2]]

*/

/* Method 1: Math

    Time: O(n)
    Space: O(1)
*/
class Solution {
    public boolean checkStraightLine(int[][] coordinates) {
        if (coordinates.length <= 2) return true;
        int slope_x = coordinates[1][0] - coordinates[0][0], slope_y = coordinates[1][1] - coordinates[0][1];
        System.out.println(slope_x + "  " + slope_y);
        for (int i = 2; i < coordinates.length; ++i) {
            if ((coordinates[i][1] - coordinates[0][1]) * slope_x != (coordinates[i][0] - coordinates[0][0]) * slope_y) {
                return false;
            }
        }
        return true;
    }

}
// @lc code=end
