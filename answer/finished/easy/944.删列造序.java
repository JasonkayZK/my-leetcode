/*
 * @lc app=leetcode.cn id=944 lang=java
 *
 * [944] 删列造序
 */

/* Test Case:

["cba", "daf", "ghi"]
["a", "b"]
["zyx", "wvu", "tsr"]

*/

/* Method 1: Brute Force

    Time: O(m * n)
    Space: O(1)
    m = A.length, n = A[i].length()
*/
class Solution {
    public int minDeletionSize(String[] A) {
        int res = 0;
        for (int i = 0; i < A[0].length(); ++i) {
            for (int j = 0; j < A.length - 1; ++j) {
                if (A[j].charAt(i) > A[j + 1].charAt(i)) {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
}

