#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"

class Solution {
 private:

 public:

  bool hasAlternatingBits(int n) {
    long long x = n ^ (n >> 1);
    return ((x + 1) & x) == 0;
  }

};

int main() {

  return 0;
}
