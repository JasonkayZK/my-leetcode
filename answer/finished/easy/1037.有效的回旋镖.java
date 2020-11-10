/*
 * @lc app=leetcode.cn id=1037 lang=java
 *
 * [1037] 有效的回旋镖
 */


/* Test Case:

[[1,1],[2,3],[3,2]]
[[1,1],[2,2],[3,3]]

*/

/* Method 1: Math

    Time: O(1)
    Space: O(1)
*/

// @lc code=start
class Solution {
    public boolean isBoomerang(int[][] points) {
        return (points[2][1] - points[0][1]) * (points[1][0] - points[0][0]) != (points[1][1] - points[0][1]) * (points[2][0] - points[0][0]);
    }
}
// @lc code=end

