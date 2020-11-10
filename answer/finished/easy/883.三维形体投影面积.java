/*
 * @lc app=leetcode.cn id=883 lang=java
 *
 * [883] 三维形体投影面积
 */

/* Test Case:

[[2]]
[[1,2],[3,4]]
[[1,0],[0,2]]
[[1,1,1],[1,0,1],[1,1,1]]
[[2,2,2],[2,1,2],[2,2,2]]

*/


/* Method 1: Brute Force 

    Time: O(3n)
    Space: O(1), n = count(g)
*/
class Solution {
    public int projectionArea(int[][] g) {
        return front(g) + left(g) + hover(g);
    }

    private int front(int[][] g) {
        int res = 0, rowMax = 0;
        for (int i = 0; i < g.length; ++i) {
            rowMax = 0;
            for (int j = 0; j < g[0].length; ++j) {
                rowMax = Math.max(rowMax, g[i][j]);
            }
            res += rowMax;
        }
        return res;
    }

    private int left(int[][] g) {
        int res = 0, colMax = 0;
        for (int j = 0; j < g[0].length; ++j) {
            colMax = 0;
            for (int i = 0; i < g.length; ++i) {
                colMax = Math.max(colMax, g[i][j]);
            }
            res += colMax;
        }
        return res;
    }

    private int hover(int[][] g) {
        int res = 0;
        for (int[] a : g) {
            for (int n : a) {
                if (n > 0) res++;
            }
        }
        return res;
    }

}

