#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int minimumSum(int num) {
    vector<int> digits;
    for (int i = 0; i < 4; ++i) {
      digits.push_back(num % 10);
      num /= 10;
    }
    sort(digits.begin(), digits.end());

    return 10 * (digits[0] + digits[1]) + digits[2] + digits[3];
  }

 private:

};

int main() {

  return 0;
}
