/*
 * @lc app=leetcode.cn id=136 lang=java
 *
 * [136] 只出现一次的数字
 *
 * https://leetcode-cn.com/problems/single-number/description/
 *
 * algorithms
 * Easy (62.87%)
 * Likes:    801
 * Dislikes: 0
 * Total Accepted:    91.7K
 * Total Submissions: 145.8K
 * Testcase Example:  '[2,2,1]'
 *
 * 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
 * 
 * 说明：
 * 
 * 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
 * 
 * 示例 1:
 * 
 * 输入: [2,2,1]
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * 输入: [4,1,2,1,2]
 * 输出: 4
 * 
 */

 /* Test Case:

[1]
[2,3,2,3,1,4,4]
[2,2,1]
[4,1,2,1,2]

 */

/* Method 1: Bit Operation: 

    Time Complexity: O(n)
    Space Complexity: O(1)
*/
class Solution {
    public int singleNumber(int[] nums) {
        if (nums == null || nums.length == 0) {throw new RuntimeException("nums is Empty!");}
        int target = nums[0];
        for (int i = 1; i < nums.length; ++i) {
            target ^= nums[i];
        }
        return target;
    }
}

