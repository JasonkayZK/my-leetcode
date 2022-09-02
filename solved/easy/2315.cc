#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int countAsterisks(string s) {
    int res = 0;
    bool cnt = true;

    for (const auto &item : s) {
      if (item == '|') cnt = !cnt;
      else {
        if (cnt && item == '*') ++res;
      }
    }
    return res;
  }

 private:

};

int main() {

  Solution().countAsterisks("l|*e*et|c**o|*de|");

  return 0;
}
