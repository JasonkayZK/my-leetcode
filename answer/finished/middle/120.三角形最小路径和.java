import java.util.Arrays;
import java.util.List;

/*
 * @lc app=leetcode.cn id=120 lang=java
 *
 * [120] 三角形最小路径和
 */

/* Test Case:



*/

/* Method 1: DP: Top to Button

    Time: O(height(triangle) ^ 2)
    Space: O(1)
*/

// @lc code=start
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        for (int i = triangle.size() - 2 ; i >= 0; i--) {
            for (int j = 0; j < triangle.get(i).size(); j++) {
               triangle.get(i).set(j, triangle.get(i).get(j) + Math.min(triangle.get(i+1).get(j), triangle.get(i+1).get(j+1)));
            }
        }
        return  triangle.get(0).get(0);
    }
}
// @lc code=end

