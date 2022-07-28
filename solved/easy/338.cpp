#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

/* Method 1: DFS
class Solution {
private:

    void dfs_helper(vector<int> &res, int cur, const int n) {
        if (cur > n) return;

        res[cur] = res[cur >> 1];

        int next_cur = cur | 0b1;
        if (next_cur <= n) {
            res[next_cur] = res[cur >> 1] + 1;
        }

        dfs_helper(res, cur << 1, n);
        dfs_helper(res, next_cur << 1, n);
    }

public:

    vector<int> countBits(int n) {
        vector<int> res(n + 1);
        if (n == 0) return {0};
        if (n == 1) return {0, 1};

        res[0] = 0;
        res[1] = 1;
        dfs_helper(res, 2, n);
        return res;
    }

};
 */

/* Method 2: DP */
class Solution {
 private:

 public:

  vector<int> countBits(int n) {
    vector<int> res(n + 1);
    for (int i = 0; i <= n; ++i) {
      res[i] = res[i >> 1] + (i & 1);
    }
    return res;
  }

};

int main() {

  Solution().countBits(5);

  return 0;
}
