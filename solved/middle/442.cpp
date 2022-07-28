#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:
  vector<int> findDuplicates(vector<int> &nums) {
    int n = int(nums.size());
    if (n <= 1) return {};

    order_array(nums, n);

    vector<int> res;
    for (int i = 0; i < n; ++i) {
      if (nums[i] != i + 1) {
        res.push_back(nums[i]);
      }
    }
    return res;
  }

 private:
  void order_array(vector<int> &arr, int n) {
    for (int i = 0; i < n; ++i) {
      while (arr[i] != arr[arr[i] - 1]) {
        swap(arr[i], arr[arr[i] - 1]);
      }
    }
  }

};

int main() {

  vector<int> l = {4, 3, 2, 7, 8, 2, 3, 1};
  Solution().findDuplicates(l);

  return 0;
}
