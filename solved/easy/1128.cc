#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int numEquivDominoPairs(vector<vector<int>> &dominoes) {
    unordered_map<int, int> m;
    for (const auto &item : dominoes) ++m[calculate(item[0], item[1])];

    int res = 0;
    for (const auto &[_, v] : m) {
      if (v > 1) {
        res += ((v * (v - 1)) >> 1);
      }
    }
    return res;
  }

 private:

  int calculate(int x, int y) {
    if (x > y) {
      int temp = x;
      x = y;
      y = temp;
    }

    return x * 10 + y;
  }
};

int main() {

  return 0;
}
