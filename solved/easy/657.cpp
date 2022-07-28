#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

 public:

  bool judgeCircle(string moves) {
    int x = 0, y = 0;
    for (char move : moves) {
      if (move == 'U') y--;
      else if (move == 'D') y++;
      else if (move == 'L') x--;
      else if (move == 'R') x++;
    }
    return x == 0 && y == 0;
  }

};

int main() {

  return 0;
}
