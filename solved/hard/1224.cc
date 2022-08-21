#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int maxEqualFreq(vector<int>& nums) {
    int res = 0, cur_max = 0;
    unordered_map<int, int> freq, count;

    for (int i = 0; i < nums.size(); ++i) {
      if (count[nums[i]] > 0) {
        --freq[count[nums[i]]];
      }
      ++count[nums[i]];
      cur_max = max(cur_max, count[nums[i]]);
      ++freq[count[nums[i]]];

      bool ok = cur_max == 1 ||
          freq[cur_max] * cur_max + freq[cur_max - 1] * (cur_max - 1) == i + 1 && freq[cur_max] == 1 ||
          freq[cur_max] * cur_max + 1 == i + 1 && freq[1] == 1;
      if (ok) {
        res = max(res, i + 1);
      }
    }

    return res;
  }

 private:

};

int main() {

  return 0;
}
