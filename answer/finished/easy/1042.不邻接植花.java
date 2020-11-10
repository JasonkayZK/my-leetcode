import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/*
 * @lc app=leetcode.cn id=1042 lang=java
 *
 * [1042] 不邻接植花
 */

/* Test Case:

3
[[1,2],[2,3],[3,1]]
4
[[1,2],[3,4]]
4
[[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]

*/

/* Method 1: Create Map 

    Time: O(paths.size)
    Space: O(paths.size)
*/

class Solution {
    public int[] gardenNoAdj(int N, int[][] paths) {
        Map<Integer, Set<Integer>> graph = new HashMap<>();
        for (int i = 0; i < N; ++i) {
            graph.put(i, new HashSet<>());
        }
        
        // CreateMap
        for (int[] path : paths) {
            graph.get(path[0] - 1).add(path[1] - 1);
            graph.get(path[1] - 1).add(path[0] - 1);
        }

        int[] res = new int[N];
        for (int i = 0; i < N; ++i) {
            boolean[] used = new boolean[5];
            for (int adj : graph.get(i)) {
                used[res[adj]] = true;
            }
            for (int j = 1; j <= 4; j++) {
                if (!used[j]) {
                    res[i] = j;
                }
            }
        }
        return res;

    }
}
