#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  vector<vector<int>> largestLocal(vector<vector<int>> &grid) {
    int n = int(grid.size());
    vector<vector<int>> res(n - 2, vector<int>(n - 2));
    // 统计左上角的点
    for (int i = 0; i < n - 2; i++) {
      for (int j = 0; j < n - 2; j++) {
        int max = 0;
        for (int k = 0; k < 3; k++) {
          for (int l = 0; l < 3; l++) {
            if (grid[i + k][j + l] > max) max = grid[i + k][j + l];
          }
        }
        res[i][j] = max;    // 写入结果
      }
    }
    return res;
  }

 private:

};

int main() {

  return 0;
}
