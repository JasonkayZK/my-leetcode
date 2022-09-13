#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  /*
    res[0] = 0 * boxes[0] + 1 * boxes[1] + 2 * boxes[2] + 3 * boxes[3];
    res[1] = 1 * boxes[0] + 0 * boxes[1] + 1 * boxes[2] + 2 * boxes[3];
           = res[0] - r + l;
    res[2] = 2 * boxes[0] + 1 * boxes[1] + 0 * boxes[2] + 1 * boxes[3];
           = res[1] - r + l;
    res[3] = 3 * boxes[0] + 2 * boxes[1] + 1 * boxes[2] + 0 * boxes[3];
   */
  vector<int> minOperations(string boxes) {
    int n = int(boxes.size()), l = 0, r = 0;
    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
      if (boxes[i] == '1') {
        res[0] += i;
        ++r;
      }
    }

    for (int i = 1; i < n; ++i) {
      if (boxes[i - 1] == '1') {
        ++l;
        --r;
      }
      res[i] = res[i - 1] + l - r;
    }
    return res;
  }

 private:

};

int main() {

  return 0;
}
