/*
 * @lc app=leetcode.cn id=207 lang=java
 *
 * [207] 课程表
 */

/* Test Case:

2
[[1,0]] 
2
[[1,0],[0,1]]

*/

/* Method 1:

    Time: O(m+n)
    Space: O(n)
*/
// @lc code=start
class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        int[][] adjacent = new int[numCourses][numCourses];
        int[] marks = new int[numCourses];
        for (int[] p : prerequisites) adjacent[p[1]][p[0]] = 1;
        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(adjacent, marks, i)) return false;
        }
        return true;
    }

    private boolean dfs(int[][] adjacent, int[] marks, int i) {
        if (marks[i] == -1) return true;
        if (marks[i] == 1) return false;

        marks[i] = 1;
        for (int j = 0; j < adjacent.length; ++j) {
            if(adjacent[i][j] == 1 && !dfs(adjacent, marks, j)) return false; 
        }
        marks[i] = -1;
        return true;
    }

}
// @lc code=end

