/*
 * @lc app=leetcode.cn id=204 lang=java
 *
 * [204] 计数质数
 *
 * https://leetcode-cn.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (29.70%)
 * Likes:    192
 * Dislikes: 0
 * Total Accepted:    25.3K
 * Total Submissions: 85K
 * Testcase Example:  '10'
 *
 * 统计所有小于非负整数 n 的质数的数量。
 * 
 * 示例:
 * 
 * 输入: 10
 * 输出: 4
 * 解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
 * 
 * 
 */

/* Test Case:

0
1
2
3
4
5
134623

*/

/* Method 1: 厄拉多塞筛法

    Time: O(n)
    Space: O(n)

*/
class Solution {
    public int countPrimes(int n) {
        boolean[] map = new boolean[n];
        int count = 0;
        for (int i = 2; i < n; ++i) {
            if (!map[i]) {
                count++;
                for (int j = i + i; j < n; j += i) map[j] = true;
            }
        }
        return count;
    }
}


