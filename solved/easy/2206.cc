#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  bool divideArray(vector<int> &nums) {
    unordered_map<int, int> freq;   // 元素出现次数哈希表
    for (int num : nums) {
      ++freq[num];
    }
    return all_of(freq.begin(), freq.end(), [](auto p) { return p.second % 2 == 0; });
  }

 private:

};

int main() {

  return 0;
}
