#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int mostFrequentEven(vector<int> &nums) {
    unordered_map<int, int> m;

    for (const auto &item : nums) {
      if ((item & 1) == 0) {
        ++m[item];
      }
    }

    int res = -1, cnt = 0;
    for (const auto &[k, v] : m) {
      if (v > cnt) {
        res = k;
        cnt = v;
      } else if (v == cnt) {
        res = min(res, k);
      }
    }
    return res;
  }

 private:

};

int main() {

  return 0;
}
