#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int rotatedDigits(int n) {
    auto s = to_string(n);
    int m = int(s.size()), dp[m][2];
    memset(dp, -1, sizeof(dp));
    return dp_helper(s, m, dp, 0, false, true);
  }

 private:

  int dp_helper(const string &s, const int m, int dp[m][2], int i, bool has_diff, bool is_limit) {
    if (i == m) return has_diff;
    if (!is_limit && dp[i][has_diff] >= 0) return dp[i][has_diff];
    int res = 0;
    int up = is_limit ? s[i] - '0' : 9;
    for (int d = 0; d <= up; ++d) // 枚举要填入的数字 d
      if (diffs[d] != -1) // d 不是 3/4/7
        res += dp_helper(s, m, dp, i + 1, has_diff || diffs[d], is_limit && d == up);
    if (!is_limit) dp[i][has_diff] = res;
    return res;
  }

  static constexpr int diffs[10] = {0, 0, 1, -1, -1, 1, 1, -1, 0, 1};

};

int main() {

  return 0;
}
