/*
 * @lc app=leetcode.cn id=836 lang=java
 *
 * [836] 矩形重叠
 */

/* Test Case:



*/

/* Method 1: Math

    Time: O(1)
    Space: O(1)
*/
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        return !(rec1[2] <= rec2[0] ||   // left
                 rec1[3] <= rec2[1] ||   // bottom
                 rec1[0] >= rec2[2] ||   // right
                 rec1[1] >= rec2[3]);    // top
    }
}

