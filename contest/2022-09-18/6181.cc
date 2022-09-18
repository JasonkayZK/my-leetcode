#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int longestContinuousSubstring(string s) {
    if (s.empty()) return 0;

    int cur = 1, res = 1, n = int(s.size());
    for (int i = 1; i < n; ++i) {
      if (s[i] - s[i - 1] == 1) {
        ++cur;
      } else {
        res = max(res, cur);
        cur = 1;
      }
    }
    res = max(res, cur);
    return res;
  }

 private:

};

int main() {

  Solution().longestContinuousSubstring("abacaba");

  return 0;
}
