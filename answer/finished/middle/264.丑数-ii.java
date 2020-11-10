/*
 * @lc app=leetcode.cn id=264 lang=java
 *
 * [264] 丑数 II
 */

/* Test Case:

1
10

*/

/* Method 1: DP: dp[n] = min(dp[l2] * 2, dp[l3] * 3, dp[l5] * 5)

    Time: O(n)
    Space: O(n)
*/
// @lc code=start
class Solution {
    public int nthUglyNumber(int n) {
        if (n <= 0) throw new RuntimeException("Invalid Parameter");

        int l2 = 0, l3 = 0, l5 = 0;
        int[] dp = new int[n];
        dp[0] = 1;
        for (int i = 1; i < n; ++i) {
            dp[i] = Math.min(Math.min(dp[l2] * 2, dp[l3] * 3), dp[l5] * 5);
            if (dp[i] >= dp[l2] * 2) l2++;
            if (dp[i] >= dp[l3] * 3) l3++;
            if (dp[i] >= dp[l5] * 5) l5++;
        }

        return dp[n - 1];
    }
}
// @lc code=end

