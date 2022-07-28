#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"

class Solution {
 private:

 public:

  vector<vector<int>> threeSum(vector<int> &nums) {
    int n = nums.size();
    if (n < 3) return {};

    sort(nums.begin(), nums.end());

    vector<vector<int>> res;
    for (int i = 0; i < n - 2; ++i) {
      if (nums[i] > 0) break; // pivot below zero
      if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicate

      int j = i + 1, k = n - 1;
      while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];

        if (sum < 0) {
          while (j < k && nums[j] == nums[++j]);
        } else if (sum > 0) {
          while (j < k && nums[k] == nums[--k]);
        } else {
          res.push_back({nums[i], nums[j], nums[k]});
          while (j < k && nums[j] == nums[++j]);
          while (j < k && nums[k] == nums[--k]);
        }
      }
    }

    return res;
  }

};

int main() {

  return 0;
}
