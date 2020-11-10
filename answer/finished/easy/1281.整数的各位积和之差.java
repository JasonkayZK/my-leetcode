/*
 * @lc app=leetcode.cn id=1281 lang=java
 *
 * [1281] 整数的各位积和之差
 */

/* Test Case:

234
4421
1000

*/

/* Method 1: Brute Force 

    Time: O(log(n))
    Space: O(1)
*/
// @lc code=start
class Solution {
    public int subtractProductAndSum(int n) {
        int sum = 0, multiplySum = 1;
        while (n != 0) {
            int bit = n % 10;
            sum += bit;
            multiplySum *= bit;
            n /= 10;
        }
        return multiplySum - sum;
    }
}
// @lc code=end

