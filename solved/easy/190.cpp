#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

 public:

  uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    for (int i = 0; i < 32 && n > 0; ++i) {
      res |= (n & 1) << (31 - i);
      n >>= 1;
    }

    return res;
  }

};

int main() {

  return 0;
}
