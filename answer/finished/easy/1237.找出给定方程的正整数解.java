import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=1237 lang=java
 *
 * [1237] 找出给定方程的正整数解
 */

// @lc code=start
/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     public int f(int x, int y);
 * };
 */

/* Test Case:

1
5
2
5

*/

/* Method 1:

    Time: O()
    Space: O()
*/
class Solution {
    public List<List<Integer>> findSolution(CustomFunction customfunction, int z) {
        List<List<Integer>> res = new ArrayList<>();

        int x = 1, y = 0;
        while (customfunction.f(x, 1) <= z) {
            y = binarySearch(customfunction, x, z);
            if (y > 0) {
                List<Integer> temp = new ArrayList<>(2);
                temp.add(x);
                temp.add(y);
                res.add(temp);
            }
            x++;
        }

        return res;
    }

    private int binarySearch(CustomFunction customfunction, int x, int z) {
        int left = 1, right = 1000;
        int mid = (right - left) / 2 + left;
        while (left <= right) {
            mid = (right - left) / 2 + left;
            if (customfunction.f(x, mid) == z) return mid;
            else if (customfunction.f(x, mid) < z) left = mid + 1;
            else right = mid - 1; 
        }
        return 0;
    }
}
// @lc code=end

