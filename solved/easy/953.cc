#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  bool isAlienSorted(vector<string> &words, string order) {
    int n = int(words.size());
    if (n <= 1) return true;

    unordered_map<char, int> m;
    for (int i = 0; i < order.size(); ++i) {
      m.emplace(make_pair(order[i], i));
    }

    for (int i = 1; i < n; ++i) {
      if (!is_le(words[i - 1], words[i], m)) return false;
    }
    return true;
  }

 private:

  bool is_le(const string &s1, const string &s2, unordered_map<char, int> &m) {
    auto l1 = s1.size(), l2 = s2.size();

    int len = int(min(l1, l2)), cur = 0;
    while (cur < len) {
      if (s1[cur] != s2[cur]) {
        return m[s1[cur]] < m[s2[cur]];
      }
      ++cur;
    }
    return l1 <= l2;
  }

};

int main() {

  return 0;
}
