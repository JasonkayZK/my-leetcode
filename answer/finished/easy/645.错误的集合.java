import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=645 lang=java
 *
 * [645] 错误的集合
 *
 * https://leetcode-cn.com/problems/set-mismatch/description/
 *
 * algorithms
 * Easy (37.86%)
 * Likes:    50
 * Dislikes: 0
 * Total Accepted:    5.3K
 * Total Submissions: 14K
 * Testcase Example:  '[1,2,2,4]'
 *
 * 集合 S 包含从1到 n
 * 的整数。不幸的是，因为数据错误，导致集合里面某一个元素复制了成了集合里面的另外一个元素的值，导致集合丢失了一个整数并且有一个元素重复。
 * 
 * 给定一个数组 nums 代表了集合 S 发生错误后的结果。你的任务是首先寻找到重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [1,2,2,4]
 * 输出: [2,3]
 * 
 * 
 * 注意:
 * 
 * 
 * 给定数组的长度范围是 [2, 10000]。
 * 给定的数组是无序的。
 * 
 * 
 */

/* Test Case:

[1,1]
[1,1,3]
[1,3,3]
[1,2,2,4]
[4,1,3,3]

*/

/* Method 1: Array negativelize + Math 

    Time: O(n)
    Space: O(1)
*/

class Solution {
    public int[] findErrorNums(int[] nums) {
        int sum = 0, dup = 0, len = nums.length;       
        for (int i = 0; i < len; ++i) {
            if (nums[Math.abs(nums[i]) - 1] > 0) nums[Math.abs(nums[i]) - 1] = -nums[Math.abs(nums[i]) - 1];
            else dup = Math.abs(nums[i]);
            sum += Math.abs(nums[i]);
        }
        return new int[]{dup, dup - (sum - (len * (len + 1)) / 2)};
    }
}

