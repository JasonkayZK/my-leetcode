import java.util.HashMap;
import java.util.Map;

/*
 * @lc app=leetcode.cn id=447 lang=java
 *
 * [447] 回旋镖的数量
 *
 * https://leetcode-cn.com/problems/number-of-boomerangs/description/
 *
 * algorithms
 * Easy (54.33%)
 * Likes:    58
 * Dislikes: 0
 * Total Accepted:    5.7K
 * Total Submissions: 10.5K
 * Testcase Example:  '[[0,0],[1,0],[2,0]]'
 *
 * 给定平面上 n 对不同的点，“回旋镖” 是由点表示的元组 (i, j, k) ，其中 i 和 j 之间的距离和 i 和 k
 * 之间的距离相等（需要考虑元组的顺序）。
 * 
 * 找到所有回旋镖的数量。你可以假设 n 最大为 500，所有点的坐标在闭区间 [-10000, 10000] 中。
 * 
 * 示例:
 * 
 * 
 * 输入:
 * [[0,0],[1,0],[2,0]]
 * 
 * 输出:
 * 2
 * 
 * 解释:
 * 两个回旋镖为 [[1,0],[0,0],[2,0]] 和 [[1,0],[2,0],[0,0]]
 * 
 * 
 */

/* Test Case:

[[0,0],[1,0],[2,0]]

*/

/* Method 1: Iteration 

    Time: O(n ^ 2)
    Space: O(n)
*/

class Solution {
    public int numberOfBoomerangs(int[][] points) {
        Map<Integer, Integer> map = new HashMap<>();
        int count = 0;

        for (int i = 0; i < points.length; ++i) {
            map.clear();
            for (int j = 0; j < points.length; ++j) {
                if (i == j) continue;
                int distance = distance(points[j], points[i]);
                // 寻找和i相同距离的j
                int size = map.getOrDefault(distance, 0);
                // j 有在第二和第三位两种情况
                count += size++ * 2;
                map.put(distance, size);
            }
        }
        return count;
    }

    private int distance(int[] point1, int[] point2) {
        return (point1[0] - point2[0]) * (point1[0] - point2[0]) + (point1[1] - point2[1]) * (point1[1] - point2[1]);
    }
}

