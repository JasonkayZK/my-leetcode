#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int minAddToMakeValid(string s) {
    int res = 0, left_count = 0;
    for (const auto &item : s) {
      if (item == '(') {
        ++left_count;
      } else {
        if (left_count > 0) {
          --left_count;
        } else {
          ++res;
        }
      }
    }
    res += left_count;
    return res;
  }

 private:

};

int main() {

  return 0;
}
