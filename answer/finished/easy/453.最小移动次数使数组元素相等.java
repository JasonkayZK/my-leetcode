/*
 * @lc app=leetcode.cn id=453 lang=java
 *
 * [453] 最小移动次数使数组元素相等
 *
 * https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements/description/
 *
 * algorithms
 * Easy (52.15%)
 * Likes:    72
 * Dislikes: 0
 * Total Accepted:    5K
 * Total Submissions: 9.6K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个长度为 n 的非空整数数组，找到让数组所有元素相等的最小移动次数。每次移动可以使 n - 1 个元素增加 1。
 * 
 * 示例:
 * 
 * 
 * 输入:
 * [1,2,3]
 * 
 * 输出:
 * 3
 * 
 * 解释:
 * 只需要3次移动（注意每次移动会增加两个元素的值）：
 * 
 * [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
 * 
 * 
 */

/* Test Case:

[1]
[1,2,3]
[1,1,1]
[1,2]

*/

/* Method 1: Math 

    Time: O(2n)
    Space: O(1)

class Solution {
    public int minMoves(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        int min = Integer.MAX_VALUE;
        for (int n : nums) min = Math.min(min, n);
        int res = 0;
        for (int n : nums) res += n - min;
        return res;
    }

}
*/

/* Method 2: Math: Sum [Better]

    Time: O(n)
    Space: O(1)
*/

class Solution {
    public int minMoves(int[] nums) {
        if (nums == null || nums.length <= 0) return 0;
        long min = (long)nums[0];
        long sum = 0;
        for (int n : nums) {
            sum += (long)n;
            min = Math.min(min, n);
        }
        return (int)(sum - min * nums.length);
    }

}
