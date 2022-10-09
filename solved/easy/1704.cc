#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  bool halvesAreAlike(string s) {
    int n = int(s.size());
    if (n <= 0) return false;

    int left_cnt = 0, right_cnt = 0, i = 0, j = (n >> 1);
    while (j < n) {
      if (is_vowel.count(s[i]) > 0) ++left_cnt;
      if (is_vowel.count(s[j]) > 0) ++right_cnt;
      ++i, ++j;
    }

    return left_cnt == right_cnt;
  }

 private:

  unordered_set<char> is_vowel = {
      'a', 'e', 'i', 'o', 'u',
      'A', 'E', 'I', 'O', 'U'
  };

};

int main() {

  return 0;
}
