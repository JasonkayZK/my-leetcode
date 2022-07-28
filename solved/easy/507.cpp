#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

 public:

  bool checkPerfectNumber(int num) {
    if (num == 1) {
      return false;
    }

    int sum = 1;
    for (int d = 2; d * d <= num; ++d) {
      if (num % d == 0) {
        sum += d;
        if (d * d < num) {
          sum += num / d;
        }
      }
    }
    return sum == num;
  }

};

int main() {

  return 0;
}
