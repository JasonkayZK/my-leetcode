#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int largestPerimeter(vector<int> &nums) {
    int n = int(nums.size());
    if (n <= 2) return 0;

    sort(nums.begin(), nums.end());
    for (int i = n - 1; i >= 2; --i) {
      if (valid_triangle(nums[i - 2], nums[i - 1], nums[i]))
        return nums[i - 2] + nums[i - 1] + nums[i];
    }
    return 0;
  }

 private:

  inline bool valid_triangle(int x, int y, int z) {
    return x + y > z;
  }

};

int main() {

  vector<int> l = {1, 2, 1};
  Solution().largestPerimeter(l);

  return 0;
}
