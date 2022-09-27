#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  bool CheckPermutation(string s1, string s2) {
    int m[26];
    fill(m, m + 26, 0);
    int n = int(s1.size());
    if (s2.size() != n) return false;

    for (int i = 0; i < n; ++i) {
      ++m[s1[i] - 'a'];
      --m[s2[i] - 'a'];
    }
    for (const auto &item : m) {
      if (item != 0) return false;
    }
    return true;
  }

 private:

};

int main() {

  return 0;
}
