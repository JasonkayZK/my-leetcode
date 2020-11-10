/*
 * @lc app=leetcode.cn id=287 lang=java
 *
 * [287] 寻找重复数
 */

/* Test Case:

[1,3,4,2,2]
[3,1,3,4,2]
[3,4,2,1,1]
[3,4,1,1,1]

*/

/* Method 1: Mark-Inplace

    Time: < O(n)
    Space: O(1)
*/

// @lc code=start
class Solution {
    public int findDuplicate(int[] nums) {
        for (int i = 0; i < nums.length; ++i) {
            if (nums[Math.abs(nums[i])] < 0) return Math.abs(nums[i]);
            nums[Math.abs(nums[i])] = - nums[Math.abs(nums[i])];
        }

        throw new RuntimeException("No result");
    }
}
// @lc code=end

