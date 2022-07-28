#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  bool canIWin(int maxChoice, int desiredTotal) {
    if ((1 + maxChoice) * (maxChoice) / 2 < desiredTotal) {
      return false;
    }
    unordered_map<int, bool> memo;
    return dfs(maxChoice, 0, 0, desiredTotal, memo);
  }

 private:

  bool dfs(int maxChoice, int used, int cur_sum, int desired,
           unordered_map<int, bool> &memo) {
    if (memo.count(used) <= 0) {
      bool res = false;
      for (int i = 0; i < maxChoice; ++i) {
        if (((used >> i) & 1) == 0) { // not used
          if (i + 1 + cur_sum >= desired) {
            res = true;
            break;
          }
          if (!dfs(maxChoice, used | (1 << i), cur_sum + i + 1, desired, memo)) {
            res = true;
            break;
          }
        }
      }
      memo[used] = res;
    }
    return memo[used];
  }

};

int main() {

  std::cout << Solution().canIWin(4, 6);

  return 0;
}
