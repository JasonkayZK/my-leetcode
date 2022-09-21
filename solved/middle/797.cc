#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    vector<vector<int>> res;
    vector<int> cur;
    cur.push_back(0);
    dfs_helper(graph, res, cur, 0, int(graph.size()) - 1);
    return res;
  }

 private:

  void dfs_helper(const vector<vector<int>> &graph,
                  vector<vector<int>> &res, vector<int> &cur, int idx, const int n) {

    if (idx == n) {
      res.emplace_back(cur);
    }
    for (const auto &item : graph[idx]) {
      cur.emplace_back(item);
      dfs_helper(graph, res, cur, item, n);
      cur.pop_back();
    }
  }

};

int main() {

  return 0;
}
