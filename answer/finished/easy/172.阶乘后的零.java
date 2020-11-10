/*
 * @lc app=leetcode.cn id=172 lang=java
 *
 * [172] 阶乘后的零
 *
 * https://leetcode-cn.com/problems/factorial-trailing-zeroes/description/
 *
 * algorithms
 * Easy (39.35%)
 * Likes:    146
 * Dislikes: 0
 * Total Accepted:    17K
 * Total Submissions: 43.2K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，返回 n! 结果尾数中零的数量。
 * 
 * 示例 1:
 * 
 * 输入: 3
 * 输出: 0
 * 解释: 3! = 6, 尾数中没有零。
 * 
 * 示例 2:
 * 
 * 输入: 5
 * 输出: 1
 * 解释: 5! = 120, 尾数中有 1 个零.
 * 
 * 说明: 你算法的时间复杂度应为 O(log n) 。
 * 
 */


/* Test Case:

0
1
2
3
5
22
30

*/

/* Method 1: Math 

    Time: O(log(n))
    Space: O(1)
*/

class Solution {
    public int trailingZeroes(int n) {
        long bcs = 5;
        int ret = 0;
        while (n / bcs > 0) {
            ret += n / bcs;
            bcs *= 5;
        }
        return ret;
    }
}

