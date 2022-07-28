#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

 public:

  bool isPerfectSquare(int num) {
    int res = int(sqrt(num));
    return res * res == num;
  }

};

int main() {

  return 0;
}
