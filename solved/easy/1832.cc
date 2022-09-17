#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  bool checkIfPangram(const string &sentence) {
    bool c_map[26];
    fill(c_map, c_map + 26, false);

    for (const auto &item : sentence) {
      c_map[item - 'a'] = true;
    }

    return std::all_of(c_map, c_map + 26, [](const auto &item) { return item; });
  }

 private:

};

int main() {

  return 0;
}
