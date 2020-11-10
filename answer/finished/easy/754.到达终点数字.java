/*
 * @lc app=leetcode.cn id=754 lang=java
 *
 * [754] 到达终点数字
 *
 * https://leetcode-cn.com/problems/reach-a-number/description/
 *
 * algorithms
 * Easy (38.01%)
 * Likes:    71
 * Dislikes: 0
 * Total Accepted:    2.5K
 * Total Submissions: 6.6K
 * Testcase Example:  '1'
 *
 * 在一根无限长的数轴上，你站在0的位置。终点在target的位置。
 * 
 * 每次你可以选择向左或向右移动。第 n 次移动（从 1 开始），可以走 n 步。
 * 
 * 返回到达终点需要的最小移动次数。
 * 
 * 示例 1:
 * 
 * 
 * 输入: target = 3
 * 输出: 2
 * 解释:
 * 第一次移动，从 0 到 1 。
 * 第二次移动，从 1 到 3 。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: target = 2
 * 输出: 3
 * 解释:
 * 第一次移动，从 0 到 1 。
 * 第二次移动，从 1 到 -1 。
 * 第三次移动，从 -1 到 2 。
 * 
 * 
 * 注意:
 * 
 * 
 * target是在[-10^9, 10^9]范围中的非零整数。
 * 
 * 
 */

/* Test Case:

1
2
3
5
1235
-1
13452346
12523456
-1235125
-5
-3
-2
-1000000000

*/

/* Method 1: Math 

    Time: O(log(n))
    Space: O(1)
*/
class Solution {
    public int reachNumber(int target) {
        target = Math.abs(target);
        // 先计算1+2+3+...+x>=target的最小值，用的是一元二次方程求根公式
        long x = (long)(Math.ceil(-0.5+Math.sqrt(1+8.0*target)/2));
        // 超过target的步数为奇数?
        if ((x * x + x - 2*target) / 2 % 2 == 1) {
            // x为奇数, 则需要再走两下才能将超出变为偶数，再将之前的某次或些行走翻转方向便能减去这部分超出
            if (x % 2 == 1) return (int)(x + 2);
            // x为偶数则只需再走一下（x+1为奇数）将超出变成偶数，再将之前的某次行走翻转方向即可
            return (int)(x + 1);
        }
        // 超过target的步数为偶数，则将之前某次行走翻转方向就能减去这部分超出
        return (int)x;
    }
}


