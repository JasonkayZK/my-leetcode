#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

  int four_dirs[4][2] = {{0, -1},
                         {-1, 0},
                         {0, 1},
                         {1, 0}};

  bool is_valid_pos_and_not_boundary(const int x, const int y, const int m, const int n) {
    return x >= 0 && x < m && y >= 0 && y < n;
  }

  void bfs_helper(vector<vector<int>> &heights, vector<vector<bool>> &ocean, int x, int y, int m, int n) {
    if (ocean[x][y]) return;

    ocean[x][y] = true;
    queue<pair<int, int>> qu;
    qu.emplace(x, y);
    while (!qu.empty()) {
      auto [row, col] = qu.front();
      qu.pop();
      for (auto &four_dir : four_dirs) {
        int newRow = row + four_dir[0], newCol = col + four_dir[1];
        if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
            heights[newRow][newCol] >= heights[row][col] && !ocean[newRow][newCol]) {
          ocean[newRow][newCol] = true;
          qu.emplace(newRow, newCol);
        }
      }
    }
  }

 public:

  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    if (heights.empty() || heights[0].empty()) return {};

    int m = int(heights.size()), n = int(heights[0].size());
    vector<vector<bool>> pacific(m, vector<bool>(n, false));
    vector<vector<bool>> atlantic(m, vector<bool>(n, false));

    // from left
    for (int i = 0; i < m; ++i) {
      bfs_helper(heights, pacific, i, 0, m, n);
    }
    // from top
    for (int i = 1; i < n; ++i) {
      bfs_helper(heights, pacific, 0, i, m, n);
    }
    // from right
    for (int i = 0; i < m; ++i) {
      bfs_helper(heights, atlantic, i, n - 1, m, n);
    }
    // from bottom
    for (int i = 0; i < n - 1; ++i) {
      bfs_helper(heights, atlantic, m - 1, i, m, n);
    }

    // check both
    vector<vector<int>> res;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (pacific[i][j] && atlantic[i][j]) {
          res.push_back({i, j});
        }
      }
    }
    return res;
  }

};

int main() {

  vector<vector<int>> l = {{1, 2, 3},
                           {2, 3, 2},
                           {3, 2, 1}};
  Solution().pacificAtlantic(l);

  return 0;
}
