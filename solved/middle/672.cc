#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int flipLights(int n, int presses) {
    if (presses == 0) return 1;
    if (n == 1) return 2;
    else if (n == 2) {
      if (presses == 1) return 3;
      else return 4;
    } else {
      if (presses == 1) return 4;
      else if (presses == 2) return 7;
      else return 8;
    }
  }

 private:

};

int main() {

  return 0;
}
