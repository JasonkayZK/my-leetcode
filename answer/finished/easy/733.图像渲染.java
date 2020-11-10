/*
 * @lc app=leetcode.cn id=733 lang=java
 *
 * [733] 图像渲染
 */

/* Test Case


*/

/* Method 1: DFS

    Time: O(n^m)
    Space: O(1)
*/
class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        int parttern = image[sr][sc];
        if (parttern == newColor) return image;

        image[sr][sc] = newColor;
        if ((sr > 0) && (image[sr - 1][sc] == parttern)) floodFill(image, sr - 1, sc, newColor);
        if ((sr < image.length - 1) && (image[sr + 1][sc] == parttern)) floodFill(image, sr + 1, sc, newColor);
        if ((sc > 0) && (image[sr][sc - 1] == parttern)) floodFill(image, sr, sc - 1, newColor);
        if ((sc < image[0].length - 1) && (image[sr][sc + 1] == parttern)) floodFill(image, sr, sc + 1, newColor);
        return image;
    }
}


