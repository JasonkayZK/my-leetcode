#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  char repeatedCharacter(string s) {
    vector<int> v(26);
    for (const auto &item : s) {
      if (v[item - 'a'] > 0) return item;
      ++v[item - 'a'];
    }
    return '\0';
  }

 private:

};

int main() {

  return 0;
}
