#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

 public:

  int binaryGap(int n) {
    int max_gap = 0, cur_idx = -1, i = 0;

    while (n != 0) {
      if ((n & 0b1) == 1) {
        if (cur_idx != -1) {
          max_gap = max(max_gap, i - cur_idx);
        }
        cur_idx = i;
      }

      ++i;
      n >>= 1;
    }
    return max_gap;
  }

};

int main() {

  return 0;
}
