#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int largestIsland(vector<vector<int>> &grid) {
    int n = int(grid.size()), res = 0;
    vector<vector<int>> island(n, vector<int>(n));
    unordered_map<int, int> area;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1 && island[i][j] == 0) {
          int t = i * n + j + 1;
          area[t] = dfs(grid, i, j, island, t, n);
          res = max(res, area[t]);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 0) {
          int z = 1;
          unordered_set<int> connected;
          for (int k = 0; k < 4; k++) {
            int x = i + dir[k], y = j + dir[k + 1];
            if (!check_valid(x, y, n) || island[x][y] == 0 || connected.count(island[x][y]) > 0) {
              continue;
            }
            z += area[island[x][y]];
            connected.insert(island[x][y]);
          }
          res = max(res, z);
        }
      }
    }
    return res;
  }

 private:

  int dfs(const vector<vector<int>> &grid,
          int x, int y, vector<vector<int>> &tag, int t, int n) {
    int res = 1;
    tag[x][y] = t;
    for (int i = 0; i < 4; i++) {
      int x1 = x + dir[i], y1 = y + dir[i + 1];
      if (check_valid(x1, y1, n) && grid[x1][y1] == 1 && tag[x1][y1] == 0) {
        res += dfs(grid, x1, y1, tag, t, n);
      }
    }
    return res;
  }

  static bool check_valid(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
  }

  vector<int> dir = {0, -1, 0, 1, 0};

};

int main() {

  return 0;
}
