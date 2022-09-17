#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int maxLengthBetweenEqualCharacters(string s) {
    int res = -1;
    vector<int> first(27, -1);
    for (int i = 0, n = int(s.size()); i < n; ++i) {
      if (first[s[i] - 'a'] == -1) first[s[i] - 'a'] = i;
      else {
        res = max(res, i - first[s[i] - 'a'] - 1);
      }
    }
    return res;
  }

 private:

};

int main() {

  return 0;
}
