#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  vector<string> findWords(vector<string> &words) {
    vector<string> ans;
    string rowIdx = "12210111011122000010020202";
    for (auto &word : words) {
      bool isValid = true;
      char idx = rowIdx[tolower(word[0]) - 'a'];
      for (int i = 1; i < word.size(); ++i) {
        if (rowIdx[tolower(word[i]) - 'a'] != idx) {
          isValid = false;
          break;
        }
      }
      if (isValid) {
        ans.emplace_back(word);
      }
    }
    return ans;
  }

 private:

};

int main() {

  return 0;
}
