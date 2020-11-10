import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=56 lang=java
 *
 * [56] 合并区间
 */

/* Test Case:

[]
[[1,3],[2,6],[8,10],[15,18]]
[[1,4],[4,5]]
[[15,18],[2,6],[8,10],[1,3]]
[[1,4],[2,3]]

*/

/* Method 1: Sort and linear search 

    Time: O(nlogn) + O(n)
    Extra Space: O(1)
*/

// @lc code=start
class Solution {
    public int[][] merge(int[][] intervals) {
        if (intervals == null || intervals.length == 0) return new int[0][0];
        Arrays.sort(intervals, (x, y) -> {
            if (x[0] != y[0]) return x[0] - y[0];
            else return x[1] - y[1];
        });

        int cnt = 0;
        int[][] res = new int[intervals.length][2];
        res[cnt++] = intervals[0];
        for (int i = 1; i < intervals.length; ++i) {
            if (intervals[i][0] > res[cnt - 1][1]) res[cnt++] = intervals[i];
            else res[cnt - 1][1] = Math.max(intervals[i][1], res[cnt - 1][1]);
        }

        return Arrays.copyOf(res, cnt);
    }
}
// @lc code=end

