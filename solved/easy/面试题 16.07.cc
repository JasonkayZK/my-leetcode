#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int maximum(int a, int b) {
    return (long(a) + b + abs(long(a) - long(b))) / 2;
  }

 private:

  long abs(long x) {
    int flag = int(x >> 63);
    return (flag ^ x) - flag;
  }

};

int main() {

  return 0;
}
