#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int minimumRecolors(string blocks, int k) {
    int size = int(blocks.size());
    int i = 0, curWCnt = 0;
    while (i < k) {
      if (blocks[i] == 'W') ++curWCnt;
      ++i;
    }
    int res = curWCnt;
    while (i < size) {
      if (blocks[i] == 'W') ++curWCnt;
      if (blocks[i - k] == 'W') --curWCnt;
      res = min(res, curWCnt);
      ++i;
    }

    return res;
  }

 private:

};

int main() {

  return 0;
}
