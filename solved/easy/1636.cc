#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  vector<int> frequencySort(vector<int> &nums) {
    unordered_map<int, int> m;
    for (const auto &item : nums) {
      ++m[item];
    }
    sort(nums.begin(), nums.end(), [&](const int &x, const int &y) {
      if (m[x] != m[y]) return m[x] < m[y];
      else return x > y;
    });
    return nums;
  }

 private:

};

int main() {

  return 0;
}
