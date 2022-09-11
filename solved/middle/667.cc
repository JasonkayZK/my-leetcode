#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  vector<int> constructArray(int n, int k) {
    vector<int> res;

    for (int i = 1; i < n - k; ++i) {
      res.push_back(i);
    }
    for (int i = n - k, j = n; i <= j; ++i, --j) {
      res.push_back(i);
      if (i != j) res.push_back(j);
    }

    return res;
  }

 private:

};

int main() {

  return 0;
}
