#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

 public:

  char findTheDifference(string s, string t) {
    vector<int> char_map(26, 0);
    int n = s.size();

    for (int i = 0; i < n; ++i) {
      char_map[s[i] - 'a']--;
      char_map[t[i] - 'a']++;
    }
    char_map[t[n] - 'a']++;

    for (int i = 0; i < 26; ++i) {
      if (char_map[i] > 0) return i + 'a';
    }

    return 0;
  }

};

int main() {

  return 0;
}
