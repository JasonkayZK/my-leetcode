#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int percentageLetter(string s, char letter) {
    int n = int(s.size());
    if (n <= 0) return 0;

    int cnt = 0;
    for (const auto &item : s) {
      if (item == letter) ++cnt;
    }

    return cnt == 0 ? 0 : cnt * 100 / n;
  }

 private:

};

int main() {

  return 0;
}
