import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=581 lang=java
 *
 * [581] 最短无序连续子数组
 */

/* Test Case:



*/

/* Method 1: Sort and compare

    Time: O(nlogn)
    Space: O(n)
*/
// @lc code=start
class Solution {
    public int findUnsortedSubarray(int[] nums) {
        int[] arr = Arrays.copyOf(nums, nums.length);
        Arrays.sort(arr);

        int left = 0, right = nums.length - 1;
        while (left < nums.length && arr[left] == nums[left]) left++;
        if (left != nums.length) while (right >= 0 && arr[right] == nums[right]) right--;

        return right > left ? right - left + 1 : 0;
    }
}
// @lc code=end

