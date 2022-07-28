#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"

class Solution {
 private:

 public:

  int firstUniqChar(string s) {
    int n = s.size();
    if (n <= 0) return -1;
    if (n == 1) return 0;

    vector<int> char_to_index(26, -2);
    for (int i = 0; i < n; ++i) {
      if (char_to_index[s[i] - 'a'] == -2) char_to_index[s[i] - 'a'] = i;
      else char_to_index[s[i] - 'a'] = -1;
    }

    int res = n + 1;
    for (const auto &item : char_to_index) {
      if (item >= 0) res = min(res, item);
    }
    return res == n + 1 ? -1 : res;
  }

};

int main() {

  return 0;
}
