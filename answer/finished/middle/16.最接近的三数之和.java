import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=16 lang=java
 *
 * [16] 最接近的三数之和
 */

/* Test Case:

[-1，2，1，-4]
1

*/

/* Method 1: Two Pointer

    Time: O(nlogn) + O(n^2)
    Space: O(1)
*/
// @lc code=start
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);

        int res = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.length - 2; ++i) {
            int left = i + 1, right = nums.length - 1;
            while (left != right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (Math.abs(sum - target) < Math.abs(res - target)) res = sum;
                if (sum > target) right--;
                else left++;
            }
        }
        return res;
    }
}
// @lc code=end
