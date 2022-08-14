#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int maxScore(string s) {
    if (s.length() <= 1) return 0;

    int n = int(s.length()), res = 0;
    vector<int> pre_one_cnt(n+1);
    for (int i = 1; i <= n; ++i) {
      pre_one_cnt[i] = pre_one_cnt[i - 1] + s[i - 1] - '0';
    }
    for (int i = 1; i <= n - 1; i++) {
      int a = i - pre_one_cnt[i], b = pre_one_cnt[n] - pre_one_cnt[i];
      res = max(res, a + b);
    }
    return res;
  }

 private:

};

int main() {

  Solution().maxScore("011101");

  return 0;
}
