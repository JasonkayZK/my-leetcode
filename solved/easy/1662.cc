#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2) {
    int m = word1.size(), n = word2.size();
    int i = 0, j = 0, x1 = 0, x2 = 0;
    while (i < m && j < n) {
      if (word1[i][x1] != word2[j][x2]) return false;
      ++x1, ++x2;

      if (x1 == word1[i].size()) {
        ++i, x1 = 0;
      }
      if (x2 == word2[j].size()) {
        ++j, x2 = 0;
      }
    }
    return i == m && j == n;
  }

 private:

};

int main() {

  return 0;
}
