import java.util.HashMap;
import java.util.Map;

/*
 * @lc app=leetcode.cn id=594 lang=java
 *
 * [594] 最长和谐子序列
 */


/* Test Case:

[1,3,2,2,5,2,3,7]

*/

/* Method 1: HashMap

    Time: O(2n)
    Space: < O(n)
*/

// @lc code=start
class Solution {
    public int findLHS(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int n : nums) map.put(n, map.getOrDefault(n, 0) + 1);

        int max = 0;
        for (int key : map.keySet()) {
            if (map.containsKey(key + 1)) max = Math.max(max, map.get(key) + map.get(key + 1));
        }
        return max;
    }
}
// @lc code=end

