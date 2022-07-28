#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:
  string largestGoodInteger(string num) {
    int n = int(num.size());
    if (n <= 2) return "";

    char cur = '\0';
    for (int i = 0; i < n - 2; ++i) {
      if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
        cur = max(cur, num[i]);
      }
    }

    return cur == '\0' ? "" : string(3, cur);
  }
};
