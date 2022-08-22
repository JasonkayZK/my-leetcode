#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  vector<string> permutation(string s) {
    vector<string> res{};
    dfs(s, res, 0, int(s.size()));
    return res;
  }

 private:

  static void dfs(string &s, vector<string> &res, int cur, const int len) {
    if (cur == len) {
      res.push_back(s);
    }
    for (int i = cur; i < len; ++i) {
      swap(s[i], s[cur]);
      dfs(s, res, cur + 1, len);
      swap(s[i], s[cur]);
    }
  }

};

int main() {

  return 0;
}
