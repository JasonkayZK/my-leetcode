import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=1051 lang=java
 *
 * [1051] 高度检查器
 */

/* Test Case:

[1,1,4,2,1,3]
[1,1,1,2,3,4]

*/

/* Method 1: Sort

    Time: O(nlog(n))
    Space: O(n)
*/

class Solution {
    public int heightChecker(int[] heights) {
        int[] copy = Arrays.copyOf(heights, heights.length);
        Arrays.sort(copy);
        int count = 0;
        for (int i = 0; i < heights.length; ++i) {
            if (heights[i] != copy[i]) count++;
        }

        return count;
    }
}

