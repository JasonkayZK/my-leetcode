/*
 * @lc app=leetcode.cn id=832 lang=java
 *
 * [832] 翻转图像
 *
 * https://leetcode-cn.com/problems/flipping-an-image/description/
 *
 * algorithms
 * Easy (72.73%)
 * Likes:    123
 * Dislikes: 0
 * Total Accepted:    20.1K
 * Total Submissions: 27.7K
 * Testcase Example:  '[[1,1,0],[1,0,1],[0,0,0]]'
 *
 * 给定一个二进制矩阵 A，我们想先水平翻转图像，然后反转图像并返回结果。
 * 
 * 水平翻转图片就是将图片的每一行都进行翻转，即逆序。例如，水平翻转 [1, 1, 0] 的结果是 [0, 1, 1]。
 * 
 * 反转图片的意思是图片中的 0 全部被 1 替换， 1 全部被 0 替换。例如，反转 [0, 1, 1] 的结果是 [1, 0, 0]。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [[1,1,0],[1,0,1],[0,0,0]]
 * 输出: [[1,0,0],[0,1,0],[1,1,1]]
 * 解释: 首先翻转每一行: [[0,1,1],[1,0,1],[0,0,0]]；
 * ⁠    然后反转图片: [[1,0,0],[0,1,0],[1,1,1]]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
 * 输出: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 * 解释: 首先翻转每一行: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]]；
 * ⁠    然后反转图片: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 * 
 * 
 * 说明:
 * 
 * 
 * 1 <= A.length = A[0].length <= 20
 * 0 <= A[i][j] <= 1
 * 
 * 
 */

/* Test Case: 

[[1,1,0],[1,0,1],[0,0,0]]
[[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]

*/

/* Method 1: Brute Force: In-place

    Time: O(n^2)
    Space: O(1)
*/
class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        for (int[] line : A) {
            flipLine(line);
            for (int i = 0; i < line.length; ++i) {
                line[i] = line[i] ^ 1;
            }
        }
        return A;
    }

    private void flipLine(int[] arr) {
        int l = 0, r = arr.length - 1, swap = 0;
        while (l < r) {
            swap = arr[l];
            arr[l] = arr[r];
            arr[r] = swap;
            l++;
            r--;
        } 
    }
}

