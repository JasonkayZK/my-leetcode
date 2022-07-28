#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 private:

 public:

  string largestOddNumber(string num) {
    int n = int(num.size());
    for (int i = n - 1; i >= 0; --i) {
      if ((num[i] - '0') % 2 == 1) { // find first odd backward
        return num.substr(0, i + 1);
      }
    }
    return "";
  }

};

int main() {

  return 0;
}
