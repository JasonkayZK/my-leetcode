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

public:

    int orangesRotting(vector<vector<int>> &grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = int(grid.size()), n = int(grid[0].size());

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;

        // build init queue
        int fresh_count = 0, fruit_count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    fruit_count++;
                    q.emplace(make_pair(i, j));
                } else if (grid[i][j] == 1) {
                    fresh_count++;
                    fruit_count++;
                }
            }
        }
        if (fresh_count <= 0) return 0; // no fresh
        if (q.empty()) return -1; // has fresh, but no rotten

        int res = -1, rotten_cnt = 0;
        while (!q.empty()) {
            // cur round rotten
            int curSize = int(q.size());
            res++;

            for (int x = 0; x < curSize; ++x) {
                // rotten cur node
                auto cur = q.front();
                q.pop();
                grid[cur.first][cur.second] = 2;
                visited[cur.first][cur.second] = true;
                rotten_cnt++;

                // ready to rotten next round
                for (const auto &item: four_dirs) {
                    int next_x = cur.first + item[0], next_y = cur.second + item[1];
                    if (is_valid_pos(next_x, next_y, m, n) && // valid & not visited & fresh
                        !visited[next_x][next_y] && grid[next_x][next_y] == 1) {
                        q.emplace(make_pair(next_x, next_y));
                        visited[next_x][next_y] = true;
                    }
                }
            }
        }

        return rotten_cnt == fruit_count ? res : -1;
    }

};

int main() {

    vector<vector<int>> l = {{2, 1, 1},
                             {1, 1, 0},
                             {0, 1, 1}};
    Solution().orangesRotting(l);

    return 0;
}
