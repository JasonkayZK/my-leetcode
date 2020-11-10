import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=976 lang=java
 *
 * [976] 三角形的最大周长
 */

/* Test Case:

[2,1,2]
[1,2,1]
[3,2,3,4]
[3,6,2,3]

*/

/* Method 1: Sort 

    Time: O(n^2 * log(n)) [Worst]
    Space: O(1)
*/
class Solution {
    public int largestPerimeter(int[] A) {
        if (A.length < 3) return 0;
        Arrays.sort(A);

        for (int i = A.length - 1; i - 2 >= 0; --i) {
            if (isTriangle(A[i], A[i - 1], A[i - 2])) return A[i] + A[i - 1] + A[i - 2];
        }
        return 0;
    }

    /**
     * 判断三条边可否构成三角形 x >= y >= z
     * 
     * @param x
     * @param y
     * @param z
     * @return
     */
    private boolean isTriangle(int x, int y, int z) {
        return y + z > x;
    }
}

