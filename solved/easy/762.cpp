#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:
  int bitMask = 0b10100010100010101100;

 public:

  int countPrimeSetBits(int left, int right) {
    int res = 0;
    for (int i = left; i <= right; ++i) {
      if (((1 << __builtin_popcount(i)) & bitMask) > 0) res++;
    }
    return res;
  }

};

int main() {

  return 0;
}
