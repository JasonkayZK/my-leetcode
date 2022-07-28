#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

 public:

  int numberOfSteps(int num) {
    int cnt = 0;
    while (num) {
      if (num % 2 == 0) {
        num >>= 1;
      } else {
        --num;
      }
      ++cnt;
    }
    return cnt;
  }

};

int main() {

  return 0;
}
