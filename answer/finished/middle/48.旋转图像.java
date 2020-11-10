/*
 * @lc app=leetcode.cn id=48 lang=java
 *
 * [48] 旋转图像
 */

/* Test Case:


[[1,2,3],[4,5,6],[7,8,9]]
[[ 5, 1, 9,11],[ 2, 4, 8,10],[13, 3, 6, 7],[15,14,12,16]] 

*/

/* Method 1: Math: 先转置, 再行交换

    Time: O(n^2)
    Space: O(1)
*/
// @lc code=start
class Solution {
    public void rotate(int[][] matrix) {
        int temp = 0, n = matrix.length;

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                temp = matrix[i][j];
                matrix[i][j] = matrix[i][n - 1 - j];
                matrix[i][n - 1 - j] = temp;
            }
        }

    }
}
// @lc code=end

