#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"

class Solution {
 private:

 public:

  int deleteAndEarn(vector<int> &nums) {
    int n = nums.size();

    vector<int> sum(10001, 0);
    int min_x = 10001, max_x = 0;
    for (const auto &item : nums) {
      min_x = min(min_x, item);
      max_x = max(max_x, item);
      sum[item] += item;
    }

    return rob_helper(sum, min_x, max_x + 1);
  }

};

int main() {

  return 0;
}
