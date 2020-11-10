import java.util.HashSet;
import java.util.Set;

/*
 * @lc app=leetcode.cn id=874 lang=java
 *
 * [874] 模拟行走机器人
 */

/* Test Case:

[4,-1,3]
[]
[4,-1,4,-2,4]
[[2,4]]
[-2,-1,8,9,6]
[[-1,3],[0,1],[-1,5],[-2,-4],[5,4],[-2,-3],[5,-1],[1,-1],[5,5],[5,2]]

*/

/* Method 1: Simulation

    Time: O(n)
    Space: O(1)
*/
class Solution {

    // pos: n, w, s, e
    // Left dir++ 
    // Right dir--
    private static int[] posX = new int[] {0, -1, 0, 1};
    private static int[] posY = new int[] {1, 0, -1, 0};


    public int robotSim(int[] commands, int[][] obstacles) {
        int res = 0, curX = 0, curY = 0, dir = 0;
        Set<Long> map = new HashSet<>();

        for (int[] arr : obstacles) {
            long ox = (long) arr[0] + 30000;
            long oy = (long) arr[1] + 30000;
            map.add((ox << 16) + oy);
        }
        for (int cmd : commands) {
            if (cmd == -2) dir = (dir + 1) % 4;
            else if (cmd == -1) dir = (dir + 3) % 4;
            else {
                int nx = 0, ny = 0;
                for (int k = 0; k < cmd; ++k) {
                    nx = curX + posX[dir];
                    ny = curY + posY[dir];
                    long code = (((long)nx + 30000) << 16) + ((long) ny + 30000);
                    if (!map.contains(code)) {
                        curX = nx;
                        curY = ny;
                        res = Math.max(res, curX*curX + curY*curY);
                    } else {
                        break;
                    }
                }
            }
        }
        return res;
    }
}

