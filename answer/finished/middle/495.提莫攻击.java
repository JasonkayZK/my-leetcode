/*
 * @lc app=leetcode.cn id=495 lang=java
 *
 * [495] 提莫攻击
 */

/* Test Case:

[1,4]
2
[1,2]
2

*/

/* Method 1: Linear Search 

    Time: O(n)
    Space: O(1)
*/
// @lc code=start
class Solution {
    public int findPoisonedDuration(int[] timeSeries, int duration) {
        int res = 0, curTime = 0;
        if (timeSeries == null || timeSeries.length == 0) return 0;
        if (timeSeries.length == 1) return duration;
        curTime = timeSeries[0];
        for (int i = 1; i < timeSeries.length; ++i) {
            res += curTime + duration < timeSeries[i] ? duration : timeSeries[i] - curTime;
            curTime = timeSeries[i];
        }

        return res + duration;
    }
}
// @lc code=end

