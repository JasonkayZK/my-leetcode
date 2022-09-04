#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int findLongestChain(vector<vector<int>> &pairs) {
    sort(pairs.begin(), pairs.end(), [](auto &x, auto &y) {
      return x[1] < y[1];
    });

    int res = 0, cur = INT_MIN;
    for (const auto &item : pairs) {
      if (cur < item[0]) {
        cur = item[1];
        ++res;
      }
    }
    return res;
  }

 private:

};

int main() {

  return 0;
}
