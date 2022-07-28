#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class NumArray {
 public:
  explicit NumArray(vector<int> &nums) {
    int size = int(nums.size());
    pre_sum = vector(size, 0);
    pre_sum[0] = nums[0];
    for (int i = 1; i < size; ++i) {
      pre_sum[i] = nums[i] + pre_sum[i - 1];
    }
  }

  int sumRange(int left, int right) {
    if (left <= 0) return pre_sum[right];
    return pre_sum[right] - pre_sum[left - 1];
  }

 private:
  vector<int> pre_sum;

};

int main() {

  return 0;
}
