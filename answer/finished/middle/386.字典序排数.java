import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=386 lang=java
 *
 * [386] 字典序排数
 */

/* Test Case:

13

*/

/* Method 1: DFS 

    Time: O(n)
    Stack Space: O(log(n))
*/
// @lc code=start
class Solution {

    public List<Integer> lexicalOrder(int n) {
        List<Integer> res = new ArrayList<>(n + 5);
        dfs(res, null, n);
        return res;    
    }

    private void dfs(List<Integer> res, Integer cur, int max) {
        if (cur != null && cur > max) return;
        if (cur != null) res.add(cur);
        for (int i = 0; i <= 9; ++i) {
            if (cur == null) {
                if (i == 0) continue;
                else cur = 0;
            }
            dfs(res, cur * 10 + i, max);
        }
    }

}
// @lc code=end

