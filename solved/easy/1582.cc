#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int numSpecial(vector<vector<int>> &mat) {
    int raw = int(mat.size()), col = int(mat[0].size());

    vector<int> raw_cnt(raw), col_cnt(col);
    for (int i = 0; i < raw; ++i) {
      for (int j = 0; j < col; ++j) {
        raw_cnt[i] += mat[i][j];
        col_cnt[j] += mat[i][j];
      }
    }

    int res = 0;
    for (int i = 0; i < raw; i++) {
      for (int j = 0; j < col; j++) {
        if (mat[i][j] == 1 && raw_cnt[i] == 1 && col_cnt[j] == 1) ++res;
      }
    }

    return res;
  }

 private:

};

int main() {

  Solution().numSpecial({{0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 1, 0, 0}});

  return 0;
}
