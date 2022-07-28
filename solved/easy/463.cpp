#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:
  int prev_dirs[2][2] = {{0, -1},
                         {-1, 0}};

  bool is_valid_pos(const int x, const int y, const int m, const int n) {
    return x >= 0 && x < m && y >= 0 && y < n;
  }

 public:

  int islandPerimeter(vector<vector<int>> &grid) {
    if (grid.empty() || grid[0].empty()) return 0;

    int m = int(grid.size()), n = int(grid[0].size()), res = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          res += 4;

          for (const auto &item : prev_dirs) {
            int prev_i = i + item[0], prev_j = j + item[1];
            if (is_valid_pos(prev_i, prev_j, m, n)) {
              if (grid[prev_i][prev_j] == 1) {
                res -= 2;
              }
            }
          }
        }
      }
    }

    return res;
  }

};

int main() {

  return 0;
}
