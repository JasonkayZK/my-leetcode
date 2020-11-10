import java.util.HashSet;
import java.util.Set;

/*
 * @lc app=leetcode.cn id=202 lang=java
 *
 * [202] 快乐数
 *
 * https://leetcode-cn.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (54.63%)
 * Likes:    150
 * Dislikes: 0
 * Total Accepted:    25.5K
 * Total Submissions: 46.6K
 * Testcase Example:  '19'
 *
 * 编写一个算法来判断一个数是不是“快乐数”。
 * 
 * 一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到
 * 1。如果可以变为 1，那么这个数就是快乐数。
 * 
 * 示例: 
 * 
 * 输入: 19
 * 输出: true
 * 解释: 
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 * 
 * 
 */

/* Test Case:

1
19
208
333

*/

/* Method 1: Set 

    如果n在计算时回到之前计算过的数, 一定不是;
*/
class Solution {
    public boolean isHappy(int n) {
        if (n <= 0) {return false;}

        Set<Integer> set = new HashSet<>();

        while (n != 1) {
            set.add(n);
            n = nextNum(n);
            if (set.contains(n)) {return false;}
        }
        return true;
    }

    private int nextNum(int n) {
        int result = 0, low = 0;
        while (n != 0) {
            low = n % 10;
            result += low * low;
            n /= 10;
        }
        return result;
    }
}

