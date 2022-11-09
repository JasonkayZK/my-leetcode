#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int shortestBridge(vector<vector<int>> &&grid) {
    int n = int(grid.size());
    vector<pair<int, int>> cur;
    queue<pair<int, int>> q;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        // Step 1: Mark the first island
        if (grid[i][j] == 1) {
          q.emplace(i, j);
          grid[i][j] = visited_flag;
          while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            cur.emplace_back(x, y);
            for (const auto &d : dir) {
              int cur_x = x + d[0], cur_y = y + d[1];
              if (is_valid(cur_x, cur_y, n, n) && grid[cur_x][cur_y] == 1) {
                q.emplace(cur_x, cur_y);
                grid[cur_x][cur_y] = visited_flag;
              }
            }
          }

          // Step 2: Fill the queue
          for (const auto &[x, y] : cur) {
            q.emplace(x, y);
          }

          // Step 3: Find the second island
          int res = 0;
          while (!q.empty()) {
            int cur_round = int(q.size());
            for (int k = 0; k < cur_round; ++k) { // BFS mark
              auto [x, y] = q.front();
              q.pop();
              for (const auto &item : dir) {
                int cur_x = x + item[0], cur_y = y + item[1];
                if (is_valid(cur_x, cur_y, n, n)) {
                  if (grid[cur_x][cur_y] == 1) {
                    return res;
                  } else if (grid[cur_x][cur_y] == 0) {
                    q.emplace(cur_x, cur_y);
                    grid[cur_x][cur_y] = visited_flag;
                  }
                }
              }
            }
            ++res;
          }
        }
      }
    }

    return 0;
  }

 private:

  bool is_valid(int x, int y, int m, int n) {
    if (x >= 0 && x < m && y >= 0 && y < n) return true;
    return false;
  }

  vector<vector<int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

  int visited_flag = -1;

};

int main() {

  std::cout << Solution().shortestBridge({{1, 1, 1, 1, 1}, {1, 0, 0, 0, 1}, {1, 0, 1, 0, 1}, {1, 0, 0, 0, 1},
                                          {1, 1, 1, 1, 1}});

  return 0;
}
