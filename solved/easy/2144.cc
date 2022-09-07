#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int minimumCost(vector<int>& cost) {
    sort(cost.rbegin(), cost.rend());
    int res = 0, n = int(cost.size());
    for (int i = 0; i < n; ++i) {
      if (i % 3 != 2) {
        res += cost[i];
      }
    }
    return res;
  }

 private:

};

int main() {

  return 0;
}
