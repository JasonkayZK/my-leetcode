/*
 * @lc app=leetcode.cn id=633 lang=java
 *
 * [633] 平方数之和
 *
 * https://leetcode-cn.com/problems/sum-of-square-numbers/description/
 *
 * algorithms
 * Easy (31.17%)
 * Likes:    68
 * Dislikes: 0
 * Total Accepted:    7.7K
 * Total Submissions: 24.8K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a^2 + b^2 = c。
 * 
 * 示例1:
 * 
 * 
 * 输入: 5
 * 输出: True
 * 解释: 1 * 1 + 2 * 2 = 5
 * 
 * 
 * 
 * 
 * 示例2:
 * 
 * 
 * 输入: 3
 * 输出: False
 * 
 * 
 */

/* Test Case:

0
1
5
3
1235
234623
1235
34567

*/

/* Method 1: linear Search

    Time: O(n ^ 1/2)
    Space: O(1)

class Solution {
    public boolean judgeSquareSum(int c) {
        int l = 0, r = (int)Math.floor(Math.sqrt(c));

        while (l <= r) {
            if (isSquare(c - l * l)) return true;
            l++;
        }
        return false;
    }

    private boolean isSquare(int n) {
        return Math.abs(Math.sqrt(n) - Math.rint(Math.sqrt(n))) <= 0.00000000001;
    }
}
*/

/* Method 1: linear Search [From end]

    Time: O(n ^ 1/2)
    Space: O(1)
*/

class Solution {
    public boolean judgeSquareSum(int c) {
        int r = (int)Math.floor(Math.sqrt(c));

        while (r >= 0) {
            if (isSquare(c - r * r)) return true;
            r--;
        }
        return false;
    }

    private boolean isSquare(int n) {
        return Math.abs(Math.sqrt(n) - Math.rint(Math.sqrt(n))) <= 0.00000000001;
    }
}

