/*
 * @lc app=leetcode.cn id=693 lang=java
 *
 * [693] 交替位二进制数
 *
 * https://leetcode-cn.com/problems/binary-number-with-alternating-bits/description/
 *
 * algorithms
 * Easy (59.67%)
 * Likes:    39
 * Dislikes: 0
 * Total Accepted:    7.4K
 * Total Submissions: 12.3K
 * Testcase Example:  '5'
 *
 * 给定一个正整数，检查他是否为交替位二进制数：换句话说，就是他的二进制数相邻的两个位数永不相等。
 * 
 * 示例 1:
 * 
 * 
 * 输入: 5
 * 输出: True
 * 解释:
 * 5的二进制数是: 101
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: 7
 * 输出: False
 * 解释:
 * 7的二进制数是: 111
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: 11
 * 输出: False
 * 解释:
 * 11的二进制数是: 1011
 * 
 * 
 * 示例 4:
 * 
 * 
 * 输入: 10
 * 输出: True
 * 解释:
 * 10的二进制数是: 1010
 * 
 * 
 */

/* Test Case:

1
2
5
7
10
11

*/

/* Method 1: Bit Operation

    Time: O(log(n))
    Space: O(1)
*/
class Solution {
    public boolean hasAlternatingBits(int n) {
        if (n <= 0) return false;        
        if (n <= 2) return true;
        int pre = n & 1;
        while (n != 0) {
            int present = n >> 1 & 1;
            if (pre == present) return false;
            pre = present;
            n >>>= 1;
        }
        return true;
    }

}

