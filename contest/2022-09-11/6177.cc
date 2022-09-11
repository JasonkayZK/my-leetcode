#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int partitionString(string s) {
    bool c_map[26]{};
    int res = 0;

    for (const auto &item : s) {
      if (c_map[item - 'a']) {
        fill(c_map, c_map + 26, false);
        c_map[item - 'a'] = true;
        ++res;
      } else {
        c_map[item - 'a'] = true;
      }
    }

    ++res;

    return res;
  }

 private:

};

int main() {

  return 0;
}
