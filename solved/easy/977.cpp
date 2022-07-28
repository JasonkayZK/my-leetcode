#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

 public:

  vector<int> sortedSquares(vector<int> &nums) {
    int n = int(nums.size());
    if (n <= 0) return {};

    if (nums[0] >= 0) {
      std::transform(nums.begin(), nums.end(), nums.begin(),
                     [](int num) {
                       return std::pow(num, 2);
                     });
      return nums;
    }

    vector<int> res(n);
    int l = 0, r = n - 1, cur = r;
    while (l <= r) {
      if (abs(nums[l]) < abs(nums[r])) {
        res[cur--] = int(pow(nums[r--], 2));
      } else {
        res[cur--] = int(pow(nums[l++], 2));
      }
    }

    return res;
  }

};

int main() {

  return 0;
}
