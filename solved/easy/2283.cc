#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  bool digitCount(string num) {
    int m[11];
    fill(m, m + 10, 0);
    for (const auto &item : num) {
      ++m[item - '0'];
    }

    for (int i = 0, n = num.size(); i < n; ++i) {
      if (m[i] != (num[i] - '0')) return false;
    }
    return true;
  }

 private:

};

int main() {

  return 0;
}
