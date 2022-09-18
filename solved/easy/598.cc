#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int maxCount(int m, int n, vector<vector<int>>& ops) {
    int mina = m, minb = n;
    for (const auto& op: ops) {
      mina = min(mina, op[0]);
      minb = min(minb, op[1]);
    }
    return mina * minb;
  }

 private:



};

int main() {



  return 0;
}
