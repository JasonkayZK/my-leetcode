#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

 public:

  int subarraySum(vector<int> &nums, int k) {
    unordered_map<int, int> m;
    m[0] = 1;

    int res = 0, pre_sum = 0;
    for (const auto &item : nums) {
      pre_sum = pre_sum + item;

      if (m.find(pre_sum - k) != m.end()) {
        res += m[pre_sum - k];
      }
      m[pre_sum]++;
    }

    return res;
  }

};

int main() {

  vector<int> l = {2, 2, 2, 2, 2, 2};
  Solution().subarraySum(l, 4);

  return 0;
}
