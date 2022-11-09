#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

    int arraySign(vector<int>& nums) {
      int sign = 1;
      for (auto num : nums) {
        if (num == 0) {
          return 0;
        }
        if (num < 0) {
          sign = -sign;
        }
      }
      return sign;
    }

 private:



};

int main() {



  return 0;
}
