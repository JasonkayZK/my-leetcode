/*
 * @lc app=leetcode.cn id=1221 lang=java
 *
 * [1221] 分割平衡字符串
 */


/* Test Case:

"RLRRLLRLRL"
"RLLLLRRRLR"
"LLLLRRRR"

*/

/* Method: Greedy

    Time: O(n)
    Space: O(1)
*/
class Solution {
    public int balancedStringSplit(String s) {
        int res = 0, l = 0, r = 0;
        for (char c : s.toCharArray()) {
            if (c == 'L') l++;
            else r++;
            if (l == r) {
                l = 0;
                r = 0;
                res++;
            }
        }
        return res;
    }
}
// @lc code=end

