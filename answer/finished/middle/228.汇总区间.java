import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=228 lang=java
 *
 * [228] 汇总区间
 */

/* Test Case:

[0,1,2,4,5,7]
[0,2,3,4,6,8,9]

*/

/* Method 1: Two Pointer

    Time: O(n)
    Space: O(1)
*/
// @lc code=start
class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> res = new ArrayList<>(nums.length);
        if (nums == null || nums.length == 0) return res;

        for (int left = 0, right = 0; right < nums.length; ++right) {
            left = right;
            while (right + 1 < nums.length && nums[right + 1] == nums[right] + 1) ++right;
            if (left == right) res.add(nums[left] + "");
            else res.add(nums[left] + "->" + nums[right]);
        }
        return res;
    }
}
// @lc code=end

