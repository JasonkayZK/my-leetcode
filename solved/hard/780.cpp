#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

 public:

  bool reachingPoints(int sx, int sy, int tx, int ty) {
    while (tx > sx && ty > sy && tx != ty) {
      if (tx > ty) {
        tx %= ty;
      } else {
        ty %= tx;
      }
    }

    if (tx == sx && ty == sy) return true;
    else if (tx == sx) {
      return ty > sy && (ty - sy) % tx == 0;
    } else if (ty == sy) {
      return tx > sx && (tx - sx) % ty == 0;
    } else {
      return false;
    }
  }

};

int main() {

  return 0;
}
