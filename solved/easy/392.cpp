#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

/* Method 1: Two pointer
class Solution {
private:

public:

    bool isSubsequence(string s, string t) {
        int m = s.size(), n = t.size();

        int i = 0, j = 0;
        while (i < m && j < n) {
            auto cur = s[i];
            while (j < n && t[j] != cur) j++;
            if (j >= n) return false;
            i++;
            j++;
        }

        return i == m;
    }
};
*/

/* Method 2: DP (as cache) */
class Solution {
 private:

 public:

  bool isSubsequence(string s, string t) {
    int m = s.size(), n = t.size();
    vector<vector<int>> dp_cache(n + 1, vector<int>(26, 0));
    for (int i = 0; i < 26; i++) { // all tail can not reachable
      dp_cache[n][i] = n;
    }

    // build cache
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j < 26; j++) {
        if (t[i] == j + 'a')
          dp_cache[i][j] = i;
        else
          dp_cache[i][j] = dp_cache[i + 1][j];
      }
    }

    // use cache to find
    int add = 0;
    for (int i = 0; i < m; i++) {
      if (dp_cache[add][s[i] - 'a'] == n) {
        return false;
      }
      add = dp_cache[add][s[i] - 'a'] + 1;
    }

    return true;
  }

};

int main() {

  return 0;
}
