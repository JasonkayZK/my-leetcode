#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

  int four_dirs[4][2] = {{0, -1},
                         {0, 1},
                         {-1, 0},
                         {1, 0}};

  bool is_valid_pos(const int x, const int y, const int m, const int n) {
    return x >= 0 && x < m && y >= 0 && y < n;
  }

 public:

  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    if (mat.empty() || mat[0].empty()) return mat;
    int m = int(mat.size()), n = int(mat[0].size());

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<pair<int, int>> q;

    // init queue with zero pos
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j] == 0) {
          q.emplace(make_pair(i, j));
          visited[i][j] = true;
        }
      }
    }

    // bfs to generate
    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();

      for (const auto &item : four_dirs) {
        int next_x = x + item[0], next_y = y + item[1];
        if (is_valid_pos(next_x, next_y, m, n) && !visited[next_x][next_y]) {
          q.emplace(make_pair(next_x, next_y));
          mat[next_x][next_y] = mat[x][y] + 1;
          visited[next_x][next_y] = true;
        }
      }
    }

    return mat;
  }

};

int main() {

  vector<vector<int>> l = {{0, 0, 0},
                           {0, 1, 0},
                           {0, 0, 0}};
  Solution().updateMatrix(l);

  return 0;
}
