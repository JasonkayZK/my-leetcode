/*
 * @lc app=leetcode.cn id=504 lang=java
 *
 * [504] 七进制数
 *
 * https://leetcode-cn.com/problems/base-7/description/
 *
 * algorithms
 * Easy (46.07%)
 * Likes:    20
 * Dislikes: 0
 * Total Accepted:    5.3K
 * Total Submissions: 11.4K
 * Testcase Example:  '100'
 *
 * 给定一个整数，将其转化为7进制，并以字符串形式输出。
 * 
 * 示例 1:
 * 
 * 
 * 输入: 100
 * 输出: "202"
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: -7
 * 输出: "-10"
 * 
 * 
 * 注意: 输入范围是 [-1e7, 1e7] 。
 * 
 */

/* Test Case:

0
100
-1
-7
-0
1235
-23457

*/


/* Method 1: Math

    Time: O(log(n))
    Space: O(1)
*/

class Solution {
    public String convertToBase7(int num) {
        if (num == 0) return "0";

        boolean isNage = false;
        StringBuilder sb = new StringBuilder();
        if (num < 0) {
            isNage = true;
            num = -num;
        }

        while (num != 0) {
            sb.append(num % 7);
            num /= 7;
        }

        sb.reverse();
        return isNage ? sb.insert(0, '-').toString() : sb.toString();
    }
}

