/*
 * @lc app=leetcode.cn id=1252 lang=java
 *
 * [1252] 奇数值单元格的数目
 */

/* Test Case:

2
3
[[0,1],[1,1]]
2
2
[[0,1],[1,1]]
48
37
[[40,5]]
2
2
[[1,1],[0,0]]


*/

/* Method 1: Use Start and end as a Pointer 

    Time: O(len(indices) + O(m * n))
    Space: O(m + n)
*/

// @lc code=start
class Solution {
    public int oddCells(int n, int m, int[][] indices) {
        if (n == 0 || m == 0) return 0;
        int[] row = new int[n], col = new int[m];
        for (int[] a : indices) {
            row[a[0]]++;
            col[a[1]]++;
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                res += (row[i] + col[j]) & 1;
            } 
        }
        return res;
    }
}
// @lc code=end

