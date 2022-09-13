#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int min_pre_sum_idx = 0, n = int(gas.size());
    int min_sum = gas[0] - cost[0], full_sum = gas[0] - cost[0];

    for (int i = 1; i < n; ++i) {
      full_sum += gas[i] - cost[i];
      if (full_sum < min_sum) {
        min_pre_sum_idx = i;
        min_sum = full_sum;
      }
    }

    if (full_sum < 0) return -1;
    return (min_pre_sum_idx + 1) % n;
  }

 private:

};

int main() {

  return 0;
}
