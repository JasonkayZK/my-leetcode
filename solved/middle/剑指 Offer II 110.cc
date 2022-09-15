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
    vector<int> stk;
    int n = int(graph.size());
    stk.push_back(0);
    dfs_helper(res, stk, graph, 0, n - 1);
    return res;
  }

 private:

  void dfs_helper(vector<vector<int>> &res, vector<int> &stk,
                  const vector<vector<int>> &graph, int x, int aim) {
    if (x == aim) {
      res.push_back(stk);
    }

    for (int i = 0, n = int(graph[x].size()); i < n; ++i) {
      stk.push_back(graph[x][i]);
      dfs_helper(res, stk, graph, graph[x][i], aim);
      stk.pop_back();
    }
  }

};

int main() {

  return 0;
}
