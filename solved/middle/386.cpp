#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

  void dfs_helper(vector<int> &res, int cur, int max) {
    if (cur > max) return;

    res.push_back(cur);
    for (int i = 0; i < 10; ++i) {
      dfs_helper(res, cur * 10 + i, max);
    }
  }

 public:

  vector<int> lexicalOrder(int n) {
    if (n <= 0) return {};

    vector<int> res;
    for (int i = 1; i < 10; ++i) {
      dfs_helper(res, i, n);
    }

    return res;
  }

};

int main() {

  return 0;
}
