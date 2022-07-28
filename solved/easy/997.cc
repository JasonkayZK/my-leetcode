#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int findJudge(int n, vector<vector<int>> &trust) {
    int trusted[n + 1], to_trust[n + 1];
    fill(trusted, trusted + n + 1, 0);
    fill(to_trust, to_trust + n + 1, 0);

    for (const auto &item : trust) {
      ++to_trust[item[0]];
      ++trusted[item[1]];
    }

    int res = -1;
    for (int i = 1; i <= n; ++i) {
      if (to_trust[i] == 0 && trusted[i] == n - 1) {
        if (res == -1) res = i;
        else return -1;
      }
    }
    return res;
  }

 private:

};

int main() {

  vector<vector<int>> l = {{1, 2}};
  Solution().findJudge(2, l);

  return 0;
}
