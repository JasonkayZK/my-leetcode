/*
 * @lc app=leetcode.cn id=485 lang=java
 *
 * [485] 最大连续1的个数
 *
 * https://leetcode-cn.com/problems/max-consecutive-ones/description/
 *
 * algorithms
 * Easy (54.32%)
 * Likes:    61
 * Dislikes: 0
 * Total Accepted:    17K
 * Total Submissions: 31.2K
 * Testcase Example:  '[1,0,1,1,0,1]'
 *
 * 给定一个二进制数组， 计算其中最大连续1的个数。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,1,0,1,1,1]
 * 输出: 3
 * 解释: 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.
 * 
 * 
 * 注意：
 * 
 * 
 * 输入的数组只包含 0 和1。
 * 输入数组的长度是正整数，且不超过 10,000。
 * 
 * 
 */

/* Test Case:

[]
[0]
[1]
[1,1]
[0,0,1]
[1,0,0]
[1,1,1]
[0,0,0]
[1,1,0,1,1,1]

*/

/* Method 1: counter 

    Time: O(n)
    Space: O(1)
*/
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        
        int max = 0;
        int count = 0;
        for(int i=0; i< nums.length; i++){
            if(nums[i]==0) {
                max = Math.max(count,max);
                count = 0;
            }else{
                 count++;
            }
        }
        return Math.max(count,max);
    }
}

