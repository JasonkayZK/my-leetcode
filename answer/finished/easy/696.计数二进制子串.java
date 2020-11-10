/*
 * @lc app=leetcode.cn id=696 lang=java
 *
 * [696] 计数二进制子串
 */

/* Test Case:

"00110011"
"10101"

*/

/* Method 1: Group Array

    Time: O(n)
    Space: O(1)
*/

// @lc code=start
class Solution {
    public int countBinarySubstrings(String s) {
        int ans = 0, prev = 0, cur = 1;
        for (int i = 1; i < s.length(); ++i) {
            if (s.charAt(i) != s.charAt(i - 1)) {
                ans += Math.min(prev, cur);
                prev = cur;
                cur = 1;
            } else {
                cur++;
            }
        }
        return ans + Math.min(prev, cur);
    }
}
// @lc code=end

