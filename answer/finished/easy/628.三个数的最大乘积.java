import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=628 lang=java
 *
 * [628] 三个数的最大乘积
 */

/* Test Case:

[-1,1,2,3]
[-2,-1,1,3]
[1,2,3,4]
[-1,-2,-3,-4]

*/


/* Method 1: 

    Time: O(nlogn)
    Space: O(1)
*/
// @lc code=start
class Solution {
    public int maximumProduct(int[] nums) {
        Arrays.sort(nums);
        return Math.max(nums[0] * nums[1] * nums[nums.length - 1], nums[nums.length - 1] * nums[nums.length - 2] * nums[nums.length - 3]);
    }
}
// @lc code=end

