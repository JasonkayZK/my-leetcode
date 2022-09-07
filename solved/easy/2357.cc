#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int minimumOperations(vector<int> &nums) {
    auto us = unordered_set(nums.begin(), nums.end());
    return us.count(0) > 0 ? us.size() - 1 : us.size();
  }

 private:

};

int main() {

  return 0;
}
