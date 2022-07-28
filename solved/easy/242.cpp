#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"

class Solution {
 private:

 public:

  bool isAnagram(string s, string t) {
    int n = s.size(), m = t.size();
    if (n != m) return false;

    vector<int> map_s(26, 0), map_t(26, 0);
    for (int i = 0; i < n; ++i) {
      map_s[s[i] - 'a']++;
      map_t[t[i] - 'a']++;
    }

    return map_s == map_t;
  }

};

int main() {

  return 0;
}
