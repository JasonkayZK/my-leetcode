#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int findContentChildren(vector<int> &&g, vector<int> &&s) {
    sort(s.begin(), s.end());
    sort(g.begin(), g.end());

    int s_idx = 0, s_size = int(s.size()), res = 0;
    for (const auto &item : g) {
      while (s_idx < s_size && s[s_idx] < item) ++s_idx;
      if (s_idx >= s_size) break;
      else {
        ++s_idx;
        ++res;
      }
    }
    return res;
  }

 private:

};

int main() {

  Solution().findContentChildren({10, 9, 8, 7}, {5, 6, 7, 8});

  return 0;
}
