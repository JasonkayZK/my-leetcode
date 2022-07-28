#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

 public:

  bool canFinish(int numCourses, vector<vector<int>> &&prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> in_degree(numCourses);

    // init graph
    for (const auto &item : prerequisites) {
      adj[item[1]].push_back(item[0]); // i[1] => i[0]
      in_degree[item[0]]++;
    }

    // init topological sort queue
    queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
      if (in_degree[i] == 0) {
        q.emplace(i);
      }
    }

    int visited = 0;
    while (!q.empty()) {
      ++visited; // add visited node

      int cur = q.front();
      q.pop();
      for (auto &item : adj[cur]) { // remove cur node
        in_degree[item]--;
        if (in_degree[item] == 0) {
          q.emplace(item);
        }
      }
    }

    return visited == numCourses;
  }

};

int main() {

  Solution().canFinish(2, {{0, 1}});

  return 0;
}
