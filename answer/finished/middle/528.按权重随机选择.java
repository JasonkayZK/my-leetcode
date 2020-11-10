import java.util.ArrayList;
import java.util.List;
import java.util.Random;

/*
 * @lc app=leetcode.cn id=528 lang=java
 *
 * [528] 按权重随机选择
 */

/* Test Case:

["Solution", "pickIndex"]
[[[1]], []]
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]

*/

/* Method 1: Array and Binary Search

    Time: O(logn)
    Space: O(n)
*/
// @lc code=start
class Solution {

    private List<Integer> map;

    private int cur;

    private Random random;

    public Solution(int[] w) {
        random = new Random();
        map = new ArrayList<>(w.length);
        cur = 0;
        for (int n : w) {
            cur += n;
            map.add(cur);
        }
    }
    
    public int pickIndex() {
        int pick = random.nextInt(cur);
        int left = 0, right = map.size();
        int mid = (right - left) / 2 + left;
        while (left < right) {
            mid = (right - left) / 2 + left;
            if (pick >= map.get(left)) left++;
            else right = mid;
        }

        return left;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */
// @lc code=end

