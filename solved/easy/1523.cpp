#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"

class Solution {
 private:

 public:

  int countOdds(int low, int high) {
    return (high - low) / 2 + ((low & 1) == 1 || (high & 1) == 1 ? 1 : 0);
  }

};

int main() {

  return 0;
}
