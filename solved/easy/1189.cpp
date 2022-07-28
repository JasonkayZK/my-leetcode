#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 private:

 public:

  int maxNumberOfBalloons(string text) {
    int m[26];
    fill(m, m + 26, 0);

    for (auto &item : text) {
      m[item - 'a']++;
    }

    int res = INT_MAX;
    res = min(res, m[1]); // b
    res = min(res, m[0]); // a
    res = min(res, m['l' - 'a'] / 2); // l
    res = min(res, m['o' - 'a'] / 2); // o
    res = min(res, m['n' - 'a']); // n
    return res;
  }

};

int main() {

  return 0;
}
