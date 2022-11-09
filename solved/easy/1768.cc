#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  string mergeAlternately(string word1, string word2) {
    string res;
    int len1 = int(word1.length()), len2 = int(word2.length()), i = 0, j = 0;

    while (i < len1 && j < len2) {
      res.push_back(word1[i]);
      res.push_back(word2[j]);
      ++i, ++j;
    }

    while (i < len1) {
      res.push_back(word1[i]);
      ++i;
    }
    while (j < len2) {
      res.push_back(word2[j]);
      ++j;
    }
    return res;
  }

 private:

};

int main() {

  return 0;
}
