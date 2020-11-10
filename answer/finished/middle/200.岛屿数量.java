/*
 * @lc app=leetcode.cn id=200 lang=java
 *
 * [200] 岛屿数量
 */

/* Test Case:

[]
[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]
[["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]

*/

/* Method 1: DFS 

    Time: O(mxn)
    Space: O(mxn)

class Solution {
    
    private boolean[][] marked;

    public int numIslands(char[][] grid) {
        if (grid == null || grid.length == 0) return 0;

        int m = grid.length, n = grid[0].length;
        marked = new boolean[m][n];

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; ++j) {
                if (!marked[i][j] && grid[i][j] != '0') {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }

    private void dfs(char[][] grid, int x, int y) {
        marked[x][y] = true;
        if (x - 1 >= 0 && !marked[x - 1][y] && grid[x - 1][y] != '0') dfs(grid, x - 1, y);
        if (x + 1 < grid.length && !marked[x + 1][y] && grid[x + 1][y] != '0') dfs(grid, x + 1, y);
        if (y - 1 >= 0 && !marked[x][y - 1] && grid[x][y - 1] != '0') dfs(grid, x, y - 1);
        if (y + 1 < grid[0].length && !marked[x][y + 1] && grid[x][y + 1] != '0') dfs(grid, x, y + 1);
    }

}
*/

/* Method 2: BFS 

    Time: O(mxn)
    Space: O(max(space)) space: 最大的岛屿面积

class Solution {
    
    public int numIslands(char[][] grid) {
        if (grid == null || grid.length == 0) return 0;

        int m = grid.length, n = grid[0].length;
        int res = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    res++;

                    grid[i][j] = '0';
                    Queue<Integer> q = new LinkedList<>();
                    q.add(i * n + j);
                    while (!q.isEmpty()) {
                        int id = q.remove();
                        int r = id / n;
                        int c = id % n;

                        if (r - 1 >= 0 && grid[r - 1][c] == '1') {
                            q.add((r - 1) * n + c);
                            grid[r - 1][c] = '0';
                        }
                        if (r + 1 < m && grid[r + 1][c] == '1') {
                            q.add((r + 1) * n + c);
                            grid[r + 1][c] = '0';
                        }
                        if (c - 1 >= 0 && grid[r][c - 1] == '1') {
                            q.add(r * n + c - 1);
                            grid[r][c - 1] = '0';
                        }
                        if (c + 1 < n && grid[r][c + 1] == '1') {
                            q.add(r * n + c + 1);
                            grid[r][c + 1] = '0';
                        }
                    }
                }
            }
        }

        return res;
    }

}
*/

/* Method 3: UnionFind

    Time: O(mxn)
    Space: O(mxn)
*/
class Solution {
    class UnionFind {
        int count; // # of connected components
        int[] parent;
        int[] rank;

        public UnionFind(char[][] grid) { // for problem 200
            count = 0;
            int m = grid.length;
            int n = grid[0].length;
            parent = new int[m * n];
            rank = new int[m * n];
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] == '1') {
                        parent[i * n + j] = i * n + j;
                        ++count;
                    }
                    rank[i * n + j] = 0;
                }
            }
        }

        public int find(int i) { // path compression
            if (parent[i] != i)
                parent[i] = find(parent[i]);
            return parent[i];
        }

        public void union(int x, int y) { // union with rank
            int rootx = find(x);
            int rooty = find(y);
            if (rootx != rooty) {
                if (rank[rootx] > rank[rooty]) {
                    parent[rooty] = rootx;
                } else if (rank[rootx] < rank[rooty]) {
                    parent[rootx] = rooty;
                } else {
                    parent[rooty] = rootx;
                    rank[rootx] += 1;
                }
                --count;
            }
        }

        public int getCount() {
            return count;
        }
    }

    public int numIslands(char[][] grid) {
        if (grid == null || grid.length == 0) return 0;

        int nr = grid.length;
        int nc = grid[0].length;
        UnionFind uf = new UnionFind(grid);
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    grid[r][c] = '0';
                    if (r - 1 >= 0 && grid[r - 1][c] == '1') {
                        uf.union(r * nc + c, (r - 1) * nc + c);
                    }
                    if (r + 1 < nr && grid[r + 1][c] == '1') {
                        uf.union(r * nc + c, (r + 1) * nc + c);
                    }
                    if (c - 1 >= 0 && grid[r][c - 1] == '1') {
                        uf.union(r * nc + c, r * nc + c - 1);
                    }
                    if (c + 1 < nc && grid[r][c + 1] == '1') {
                        uf.union(r * nc + c, r * nc + c + 1);
                    }
                }
            }
        }

        return uf.getCount();
    }
}
