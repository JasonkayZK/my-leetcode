
/*
 * @lc app=leetcode.cn id=5088 lang=java
 *
 * [5088] 等差数列中缺失的数字
 */

/* Test Case:

[5,7,11,13]
[15,13,12]

*/

/* Method 1: Math

    Time: O(n)
    Space: O(1)
*/
class Solution {
    public int missingNumber(int[] arr) {
        int sum = (arr[0] + arr[arr.length - 1]) * (arr.length + 1) / 2;
        for (int n : arr) sum -= n;
        return sum;
    }
}
// @lc code=end

