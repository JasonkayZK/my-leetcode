import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;

/*
 * @lc app=leetcode.cn id=1030 lang=java
 *
 * [1030] 距离顺序排列矩阵单元格
 *
 * https://leetcode-cn.com/problems/matrix-cells-in-distance-order/description/
 *
 * algorithms
 * Easy (58.30%)
 * Likes:    11
 * Dislikes: 0
 * Total Accepted:    2.1K
 * Total Submissions: 3.6K
 * Testcase Example:  '1\n2\n0\n0'
 *
 * 给出 R 行 C 列的矩阵，其中的单元格的整数坐标为 (r, c)，满足 0 <= r < R 且 0 <= c < C。
 * 
 * 另外，我们在该矩阵中给出了一个坐标为 (r0, c0) 的单元格。
 * 
 * 返回矩阵中的所有单元格的坐标，并按到 (r0, c0) 的距离从最小到最大的顺序排，其中，两单元格(r1, c1) 和 (r2, c2)
 * 之间的距离是曼哈顿距离，|r1 - r2| + |c1 - c2|。（你可以按任何满足此条件的顺序返回答案。）
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：R = 1, C = 2, r0 = 0, c0 = 0
 * 输出：[[0,0],[0,1]]
 * 解释：从 (r0, c0) 到其他单元格的距离为：[0,1]
 * 
 * 
 * 示例 2：
 * 
 * 输入：R = 2, C = 2, r0 = 0, c0 = 1
 * 输出：[[0,1],[0,0],[1,1],[1,0]]
 * 解释：从 (r0, c0) 到其他单元格的距离为：[0,1,1,2]
 * [[0,1],[1,1],[0,0],[1,0]] 也会被视作正确答案。
 * 
 * 
 * 示例 3：
 * 
 * 输入：R = 2, C = 3, r0 = 1, c0 = 2
 * 输出：[[1,2],[0,2],[1,1],[0,1],[1,0],[0,0]]
 * 解释：从 (r0, c0) 到其他单元格的距离为：[0,1,1,2,2,3]
 * 其他满足题目要求的答案也会被视为正确，例如 [[1,2],[1,1],[0,2],[1,0],[0,1],[0,0]]。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= R <= 100
 * 1 <= C <= 100
 * 0 <= r0 < R
 * 0 <= c0 < C
 * 
 * 
 */

/* Test Case:

1
2
0
0
2
2
0
1
2
3
1
2

*/

/* Method 1: Brute Force: Java Sort 

    Time: O(n^2)
    Space: O(1)

class Solution {
    public int[][] allCellsDistOrder(int R, int C, int r0, int c0) {
        int[][] res = new int[R * C][2];
        int cur = 0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                res[cur++] = new int[] {i, j};
            }
        }
        Comparator<int[]> comp = new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return manhattanDistance(o1[0], o1[1], r0, c0) - manhattanDistance(o2[0], o2[1], r0, c0);
            }
        };
        Arrays.sort(res, comp);
        return res;
    }

    private int manhattanDistance(int r1, int c1, int r2, int c2) {
        return Math.abs(r1 - r2) + Math.abs(c1 - c2);
    }
}
*/

/* Method 2: Math

    Time: O(n^2)
    Space: O(1)
*/
class Solution {
    public int[][] allCellsDistOrder(int R, int C, int r0, int c0) {
        int[] l = new int[4];
        l[0] = r0 + c0;
        l[1] = r0 + C - 1 - c0;
        l[2] = R - 1 - r0 + c0;
        l[3] = R - 1 - r0 + C - 1 - c0;
        int m = 0;
        for(int i : l) {
            if(i > m) {
                m = i;
            }
        }
        
        int[][] ref= new int[R * C][2];
        int idx = 1;
        ref[0][0] = r0;
        ref[0][1] = c0;
        for(int i = 1; i <= m; i++) {
            for(int x = 0; x <= i; x++) {
                if(r0 - x >= 0 && c0 - (i - x) >= 0) {
                    ref[idx][0] = r0 - x;
                    ref[idx++][1] = c0 - (i - x);
                }
                if(r0 + x <= R - 1 && c0 - (i - x) >= 0 && x != 0 && i != x) {
                    ref[idx][0] = r0 + x;
                    ref[idx++][1] = c0 - (i - x);              
    
                }
                if(r0 - x >= 0 && c0 + (i - x) <= C - 1  && x != 0 && i != x) {
                    ref[idx][0] = r0 - x;
                    ref[idx++][1] = c0 + (i - x);              
    
                }
                if(r0 + x <= R - 1 && c0 + (i - x) <= C - 1) {
                    ref[idx][0] = r0 + x;
                    ref[idx++][1] = c0 + (i - x);         
    
                }
            }    
        }
        return ref;
    }

}



