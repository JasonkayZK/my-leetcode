#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

 public:

  void rotate(vector<int> &nums, int k) {
    int n = int(nums.size());
    if (n <= 1) return;

    k = k % n;
    if (k == 0) return;

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k + 1, nums.end());
  }

};

int main() {

  return 0;
}
