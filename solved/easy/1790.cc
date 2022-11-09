#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  bool areAlmostEqual(string s1, string s2) {
    int n = int(s1.size());
    vector<char> diff;
    for (int i = 0; i < n; ++i) {
      if (s1[i] != s2[i]) {
        if (diff.size() >= 2) {
          return false;
        }
        diff.emplace_back(i);
      }
    }
    if (diff.empty()) return true;
    if (diff.size() != 2) return false;
    return s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]];
  }

 private:

};

int main() {

  return 0;
}
