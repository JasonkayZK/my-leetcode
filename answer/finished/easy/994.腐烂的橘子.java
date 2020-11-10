import java.util.LinkedList;
import java.util.Queue;

/*
 * @lc app=leetcode.cn id=994 lang=java
 *
 * [994] 腐烂的橘子
 */

/* Test Case:

[[2,1,1],[1,1,0],[0,1,1]]
[[2,1,1],[0,1,1],[1,0,1]]
[[0,2]]

*/

/* Method 1: BFS 

    Time: O(3*n)
    Space: O(n)
*/
class Solution {
    
    class Orange {
        int x, y;
        public Orange(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    private static int[] posX = new int[] {1, 0, -1, 0};
    private static int[] posY = new int[] {0, 1, 0, -1};

    public int orangesRotting(int[][] grid) {
        int res = 0;
        int len1 = grid.length, len2 = grid[0].length;
        Queue<Orange> queue = new LinkedList<>();
        for (int i = 0; i < len1; ++i) {
            for (int j = 0; j < len2; ++j) {
                if (grid[i][j] == 2) {
                    queue.offer(new Orange(i, j));
                }
            }
        }
        
        int size = queue.size();
        boolean finished = true;
        while (!queue.isEmpty()) {
            size = queue.size();
            finished = true;
            for (int i = 0; i < size; ++i) {
                Orange c = queue.poll();
                for (int j = 0; j < 4; ++j) {
                    if (c.x + posX[j] < 0 || c.x + posX[j] >= len1 ||
                        c.y + posY[j] < 0 || c.y + posY[j] >= len2 ||
                        grid[c.x + posX[j]][c.y + posY[j]] != 1) {
                            continue;
                    }
                    finished = false;
                    grid[c.x + posX[j]][c.y + posY[j]] = 2;
                    queue.offer(new Orange(c.x + posX[j], c.y + posY[j]));
                }
            }
            if (!finished) {
                res++;
            }
        }
        for (int i = 0; i < len1; ++i) {
            for (int j = 0; j < len2; ++j) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return res;
    }
}
