/*
 * @lc app=leetcode.cn id=5295 lang=java
 *
 * [5295] 和为零的N个唯一整数
 */

/* Test Case:

1
2
3
4
5
6
7

*/

// @lc code=start
/* Method 1:

    Time: O(n/2)
    Extra Space: O(1)
*/
class Solution {
    public int[] sumZero(int n) {
        int num = 1, cur = 0;
        int[] res = new int[n];
        
        if ((n & 1) == 1) {
            res[cur++] = 0;
        } 
        for (; cur < n - 1; cur += 2) {
            res[cur] = num;
            res[cur + 1] = -num;
            num++;
        }
        return res;
    }
}
// @lc code=end

