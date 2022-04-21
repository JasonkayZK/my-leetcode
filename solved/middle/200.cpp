#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:

    int four_dirs[4][2] = {{0,  -1},
                           {0,  1},
                           {-1, 0},
                           {1,  0}};

    bool is_valid_pos(const int x, const int y, const int m, const int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    void mark(const vector<vector<char>> &grid, vector<vector<bool>> &visited,
              int x, int y, int m, int n) {

        queue<pair<int, int>> q;
        q.emplace(make_pair(x, y));
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            visited[cur.first][cur.second] = true;

            for (const auto &item: four_dirs) {
                int next_x = cur.first + item[0], next_y = cur.second + item[1];
                if (is_valid_pos(next_x, next_y, m, n) && !visited[next_x][next_y] && grid[next_x][next_y] == '1') {
                    q.emplace(make_pair(next_x, next_y));
                    visited[next_x][next_y] = true;
                }
            }
        }
    }

public:

    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int m = int(grid.size()), n = int(grid[0].size());
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    mark(grid, visited, i, j, m, n);
                    res++;
                }
            }
        }
        return res;
    }

};

int main() {

    vector<vector<char>> l = {
            {'1', '1', '1', '1', '0'},
            {'1', '1', '0', '1', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '0', '0', '0'},
    };
    Solution().numIslands(l);

    return 0;
}
