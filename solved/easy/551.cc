#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  bool checkRecord(string s) {
    int a_cnt = 0;
    for (int i = 0, n = int(s.size()); i < n; ++i) {
      if (s[i] == 'A') ++a_cnt;
      else if (i < n - 2 && s[i] == 'L' && s[i + 1] == 'L' && s[i + 2] == 'L') return false;
    }
    return a_cnt < 2;
  }

 private:

};

int main() {

  return 0;
}
