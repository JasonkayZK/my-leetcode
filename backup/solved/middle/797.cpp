#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <memory>
#include <cmath>
#include <numeric>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <queue>

using namespace std;

class Solution {
 private:

  vector<vector<int>> res;
  vector<int> stack;

 public:

  void dfs(vector<vector<int>> &graph, int node, int aimNode) {
    if (node == aimNode) {
      res.push_back(stack);
      return;
    }

    for (auto &y : graph[node]) {
      stack.push_back(y);
      dfs(graph, y, aimNode);
      stack.pop_back();
    }

  }

  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    stack.push_back(0);
    dfs(graph, 0, int(graph.size()) - 1);
    return res;
  }
};
