/*
 * @lc app=leetcode.cn id=643 lang=java
 *
 * [643] 子数组最大平均数 I
 */

/* Test Case:

[1,12,-5,-6,50,3]
4

*/

/* Method 1: Sliding window

    Time: O(n)
    Space: O(1)
*/
// @lc code=start
class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int sum = 0;
        for(int  i= 0; i < k; ++i) {
            sum += nums[i];
        }
        
        //记录第一个i  和  i+k   sum+nums[i+k-1]-nums[i-1];
        int temp = sum;
        for(int i = 1; i + k - 1 < nums.length; ++i) {
            temp = temp + nums[i + k - 1] - nums[i-1];
            if(temp > sum) sum = temp;
        }
        
        return sum / (double)k;
    }
}
// @lc code=end

