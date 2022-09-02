#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  bool checkXMatrix(vector<vector<int>> &grid) {
    int n = grid.size();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j || (i + j) == grid.size() - 1) {
          if (grid[i][j] == 0)return false;
        } else {
          if (grid[i][j] != 0)return false;
        }
      }
    }
    return true;
  }

 private:

};

int main() {

  return 0;
}
