/*
 * @lc app=leetcode.cn id=566 lang=java
 *
 * [566] 重塑矩阵
 */

/* Test Case:

[[1,2],[3,4]]
1
4
[[1,2],[3,4]]
2
4

*/

/* Method 1:

    Time: O(n^2)
    Space: O(1)
*/
class Solution {
    public int[][] matrixReshape(int[][] nums, int r, int c) {
        int raw = nums.length, col = nums[0].length;
        if (raw * col != r * c) return nums;

        int rIndex = 0, cIndex = 0;
        int[][] res = new int[r][c];
        for (int[] arr : nums) {
            for (int num : arr) {
                res[rIndex][cIndex] = num;
                cIndex++;
                if (cIndex == c) {
                    cIndex = 0;
                    rIndex++;
                }
            }
        }
        return res;
    }
}

