#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  bool isPathCrossing(string path) {
    unordered_set<int> s;

    int x = 0, y = 0;
    s.emplace(0);
    for (const auto &item : path) {
      if (item == 'N') --y;
      else if (item == 'S') ++y;
      else if (item == 'W') --x;
      else ++x;
      int hash = my_hash(x, y);
      if (s.count(hash) > 0) return true;
      else s.emplace(hash);
    }
    return false;
  }

 private:

  int my_hash(int x, int y) {
    return x * 100000 + y;
  }

};

int main() {

  Solution().isPathCrossing("NES");

  return 0;
}
