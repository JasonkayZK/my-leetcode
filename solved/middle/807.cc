#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int maxIncreaseKeepingSkyline(vector<vector<int>> &grid) {
    int n = int(grid.size());
    vector<vector<int>> raw_col_max(n, vector<int>(2, 0));

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        raw_col_max[i][0] = max(raw_col_max[i][0], grid[i][j]);
        raw_col_max[j][1] = max(raw_col_max[j][1], grid[i][j]);
      }
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        res += min(raw_col_max[i][0], raw_col_max[j][1]) - grid[i][j];
      }
    }
    return res;
  }

 private:

};

int main() {

  return 0;
}
