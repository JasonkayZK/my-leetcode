#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  vector<int> minSubsequence(vector<int> &nums) {
    if (nums.size() <= 1) return nums;

    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    sort(nums.rbegin(), nums.rend());
    vector<int> result;
    int curSum = 0;
    for (const auto &item : nums) {
      curSum += item;
      result.emplace_back(item);
      if (sum - curSum < curSum) break;
    }
    return result;
  }

 private:

};

int main() {

  return 0;
}
