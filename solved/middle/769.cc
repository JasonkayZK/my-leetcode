#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int maxChunksToSorted(vector<int> &arr) {
    int cur = 0, res = 0;
    for (int i = 0; i < arr.size(); ++i) {
      cur = max(cur, arr[i]);
      if (cur == i) {
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
