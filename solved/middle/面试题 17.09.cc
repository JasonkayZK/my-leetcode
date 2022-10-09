#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  /* Method 1: Heap
  int getKthMagicNumber(int k) {
    unordered_set<long> seen;
    priority_queue<long, vector<long>, greater<long> > q;
    seen.insert(1L);
    q.push(1L);
    int res = 0;
    for (int i = 0; i < k; ++i) {
      long curr = q.top();
      q.pop();
      res = (int) curr;
      for (int factor : factors) {
        long next = curr * factor;
        if (!seen.count(next)) {
          seen.insert(next);
          q.push(next);
        }
      }
    }
    return res;
  }
   */

  /* Method 2: DP */
  int getKthMagicNumber(int k) {
    vector<int> dp(k + 1);
    dp[1] = 1;
    int p3 = 1, p5 = 1, p7 = 1;
    for (int i = 2; i <= k; ++i) {
      int n3 = dp[p3] * 3, n5 = dp[p5] * 5, n7 = dp[p7] * 7;
      dp[i] = min({n3, n5, n7});
      if (dp[i] == n3) ++p3;
      if (dp[i] == n5) ++p5;
      if (dp[i] == n7) ++p7;
    }
    return dp[k];
  }

 private:

};

int main() {

  return 0;
}
