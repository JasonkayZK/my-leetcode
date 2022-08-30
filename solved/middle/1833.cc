#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int maxIceCream(vector<int>& costs, int coins) {
    sort(costs.begin(), costs.end());
    int res = 0;
    for (const auto &item : costs) {
      if (coins - item >= 0) {
        coins -= item;
        ++res;
      }
      if (coins <= 0) break;
    }
    return res;
  }

 private:



};

int main() {



  return 0;
}
