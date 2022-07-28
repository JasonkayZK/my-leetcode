#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

 public:

  int hammingDistance(int x, int y) {
    return __builtin_popcount(x ^ y);
  }

};

int main() {

  return 0;
}
