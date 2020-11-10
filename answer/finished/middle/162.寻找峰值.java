/*
 * @lc app=leetcode.cn id=162 lang=java
 *
 * [162] 寻找峰值
 */

// @lc code=start
/* Test Case:

[1,2]
[1,2,3,1]
[1,2,1,3,5,6,4]

*/

/* Method 1: Binary Search

    Time: O(log(n))
    Space: O(1)

class Solution {
    public int findPeakElement(int[] nums) {
        int left = 0, right = nums.length - 1;
        int mid = left + (right - left) / 2, mid2 = mid + 1;
        while (left < right) {
            mid = left + (right - left) / 2;
            mid2 = mid + 1;
            if (nums[mid2] > nums[mid]) left = mid2;
            else right = mid;
        }
        return left;
    }
}
*/

/* Method 2: Recursive

    Time: O(log(n))
    Space: O(1)
*/
class Solution {
    public int findPeakElement(int[] nums) {
        return helper(nums, 0, nums.length - 1);
    }

    private int helper (int[] nums, int left, int right) {
        if (left == right) return left;
        int mid = left + (right - left) / 2, mid2 = mid + 1;
        if (nums[mid2] > nums[mid]) return helper(nums, mid2, right);
        else return helper(nums, left, mid);
    }
}
// @lc code=end

