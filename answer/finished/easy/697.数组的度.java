import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=697 lang=java
 *
 * [697] 数组的度
 *
 * https://leetcode-cn.com/problems/degree-of-an-array/description/
 *
 * algorithms
 * Easy (48.92%)
 * Likes:    69
 * Dislikes: 0
 * Total Accepted:    5.6K
 * Total Submissions: 11.4K
 * Testcase Example:  '[1,2,2,3,1]'
 *
 * 给定一个非空且只包含非负数的整数数组 nums, 数组的度的定义是指数组里任一元素出现频数的最大值。
 * 
 * 你的任务是找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1, 2, 2, 3, 1]
 * 输出: 2
 * 解释: 
 * 输入数组的度是2，因为元素1和2的出现频数最大，均为2.
 * 连续子数组里面拥有相同度的有如下所示:
 * [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
 * 最短连续子数组[2, 2]的长度为2，所以返回2.
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [1,2,2,3,1,4,2]
 * 输出: 6
 * 
 * 
 * 注意:
 * 
 * 
 * nums.length 在1到50,000区间范围内。
 * nums[i] 是一个在0到49,999范围内的整数。
 * 
 * 
 */

/* Test Case:

[0]
[0,1]
[1,1]
[1,2,1,3,2,1,2,2,2,2]
[1, 2, 2, 3, 1]
[1,2,2,3,1,4,2]
[2,1,1,2,1,3,3,3,1,3,1,3,2]

*/

/* Method 1: HashMap-Array + counter 

    Time: O(n)
    Space: O(1)

    Map: 
        1. arr[i] % 50000 = firstShownIndex
        2. arr[i] / 50000 = degree
*/

class Solution {
    public int findShortestSubArray(int[] nums) {
        long[] dict = new long[50000];
        Arrays.fill(dict, -1L);

        long min = Integer.MAX_VALUE, degree = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (dict[nums[i]] == -1) dict[nums[i]] = i + 50000 * 1L;
            else dict[nums[i]] += 50000;
            
            if (degree < dict[nums[i]] / 50000) {
                degree = dict[nums[i]] / 50000;
                min = i - dict[nums[i]] % 50000;
            } 
            if (degree == dict[nums[i]] / 50000) {
                min = Math.min(i - dict[nums[i]] % 50000, min);
            }
        }
        return (int)min + 1;
    }
}

