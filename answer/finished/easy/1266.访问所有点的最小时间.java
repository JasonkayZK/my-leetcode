/*
 * @lc app=leetcode.cn id=1266 lang=java
 *
 * [1266] 访问所有点的最小时间
 */

/* Test Case:

[[1,1],[3,4],[-1,0]]
[[3,2],[-2,2]]

*/
// @lc code=start
class Solution {

    public int minTimeToVisitAllPoints(int[][] points) {
        int min = 0;
        for (int i = 1; i < points.length; ++i)
            min += findMinStep(points[i - 1][0], points[i - 1][1], points[i][0], points[i][1]);
        return min;
    }

    private static int findMinStep(int x1, int y1, int x2, int y2) {
        int minSlope = Math.min(Math.abs(x1 - x2), Math.abs(y1 - y2));
        return Math.abs(x1 - x2) + Math.abs(y1 - y2) - minSlope;
    }
}
// @lc code=end

