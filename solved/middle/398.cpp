#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

  unordered_map<int, vector<int>> m;

 public:

  Solution(vector<int> &nums) {
    int n = int(nums.size());

    for (int i = 0; i < n; ++i) {
      m[nums[i]].push_back(i);
    }
  }

  int pick(int target) {
    int cnt = int(m[target].size());
    return m[target][rand() % cnt];
  }

};

int main() {

  return 0;
}
