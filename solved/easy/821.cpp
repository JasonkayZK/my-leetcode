#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

 public:

  vector<int> shortestToChar(string s, char c) {
    int n = int(s.size());
    if (n <= 0) return {};

    vector<int> res(n);

    // left to right
    int idx = -n;
    for (int i = 0; i < n; ++i) {
      if (s[i] == c) {
        idx = i;
      }
      res[i] = i - idx;
    }

    // right to left
    idx = 2 * n;
    for (int i = n - 1; i >= 0; --i) {
      if (s[i] == c) {
        idx = i;
      }
      res[i] = min(res[i], idx - i);
    }

    return res;
  }

};

int main() {

  return 0;
}
