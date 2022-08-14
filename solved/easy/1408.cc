#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  vector<string> stringMatching(vector<string> &words) {
    vector<string> ret;
    for (int i = 0; i < words.size(); i++) {
      for (int j = 0; j < words.size(); j++) {
        if (i != j && words[j].find(words[i]) != string::npos) {
          ret.push_back(words[i]);
          break;
        }
      }
    }
    return ret;
  }

 private:

};

int main() {

  return 0;
}
