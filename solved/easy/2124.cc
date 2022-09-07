#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  bool checkString(string s) {
    bool shown_b = false;

    for (const auto &item : s) {
      if (item == 'b' && !shown_b) shown_b = true;
      if (item == 'a' && shown_b) return false;
    }
    return true;
  }

 private:

};

int main() {

  return 0;
}
