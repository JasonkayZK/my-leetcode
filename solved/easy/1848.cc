#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int getMinDistance(vector<int>& nums, int target, int start) {
    int res = nums.size();
    for (int i = 0; i < nums.size(); ++i){
      if (nums[i] == target){
        res = min(res, abs(i - start));
      }
    }
    return res;
  }

 private:



};

int main() {



  return 0;
}
