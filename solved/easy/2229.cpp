#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

 public:

  bool isConsecutive(vector<int> &nums) {
    int n = int(nums.size());
    if (n <= 1) return true;

    unordered_set<int> s(n);
    int l = nums[0], r = nums[0];
    for (const auto &item : nums) {
      if (s.count(item) > 0) return false;

      s.insert(item);
      l = min(l, item);
      r = max(r, item);
    }

    return s.size() == n && (r - l) == n - 1;
  }

};

int main() {

  return 0;
}
