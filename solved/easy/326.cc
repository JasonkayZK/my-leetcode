#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  bool isPowerOfThree(int n) {
    if (n == 1) return true;
    if (n < 3) return false;

    while (n % 3 == 0) {
      n /= 3;
    }
    return n == 1;
  }

 private:

};

int main() {

  return 0;
}
