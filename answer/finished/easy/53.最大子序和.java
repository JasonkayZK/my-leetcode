/*
 * @lc app=leetcode.cn id=53 lang=java
 *
 * [53] 最大子序和
 *
 * https://leetcode-cn.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (46.91%)
 * Likes:    1126
 * Dislikes: 0
 * Total Accepted:    82.6K
 * Total Submissions: 176K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 
 * 示例:
 * 
 * 输入: [-2,1,-3,4,-1,2,1,-5,4],
 * 输出: 6
 * 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 * 
 * 
 * 进阶:
 * 
 * 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 * 
 */

/* Test Case:

[-2,1,-3,4,-1,2,1,-5,4]
[1]
[2,1]
[-100,2,3,-100]
[-1,2,3,100]

*/

 /* Method 1: DP 
 
    Time Complexity: O(n)
    Space Complexity: O(n)

class Solution {
    public int maxSubArray(int[] nums) {
        if (nums == null || nums.length == 0) {throw new RuntimeException("At least one number!");}

        int[] dp = new int[nums.length];
        dp[0] = nums[0];
        int max = nums[0];
        for (int i = 1; i < nums.length; ++i) {
            dp[i] = Math.max(nums[i], dp[i - 1] + nums[i]);
            max = Math.max(dp[i], max);
        }
        return max;
    }
} 
*/

/* Method 1: DP [Optimized]

    Time Complexity: O(n)
    Space Complexity: O(1)
*/
class Solution {
    public int maxSubArray(int[] nums) {
        if (nums == null || nums.length == 0) {throw new RuntimeException("At least one number!");}

        int lastGreater = 0;
        int largestSum = Integer.MIN_VALUE;
        for (int num : nums) {
            lastGreater += num;
            if (lastGreater > largestSum) {
                largestSum = lastGreater;
            }
            if (lastGreater <= 0) {
                lastGreater = 0;
            }
        }
        return largestSum;
    }
} 


