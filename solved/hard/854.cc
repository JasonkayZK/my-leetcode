#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  int kSimilarity(string s1, string s2) {
    int n = int(s1.size());
    queue<pair<string, int> > q;
    unordered_set<string> visited;
    q.emplace(s1, 0);
    visited.emplace(s1);
    for (int step = 0;; ++step) {
      int sz = q.size();
      for (int i = 0; i < sz; ++i) {
        auto [cur, pos] = q.front();
        q.pop();
        if (cur == s2) {
          return step;
        }
        while (pos < n && cur[pos] == s2[pos]) {
          pos++;
        }
        for (int j = pos + 1; j < n; j++) {
          if (cur[j] != s2[j] && cur[j] == s2[pos]) { // 剪枝，只在 cur[j] != s2[j] 时去交换
            swap(cur[pos], cur[j]);
            if (!visited.count(cur)) {
              visited.emplace(cur);
              q.emplace(cur, pos + 1);
            }
            swap(cur[pos], cur[j]);
          }
        }
      }
    }
  }

 private:

};

int main() {

  return 0;
}
