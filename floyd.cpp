#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

  vector<bool> floyd(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries) {
    int n = numCourses;
    vector<vector<bool>> dp(n, vector<bool>(n, 0));

    for (auto &pre : prerequisites) {
      dp[pre[0]][pre[1]] = true;
    }

    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          dp[i][j] = dp[i][j] || (dp[i][k] && dp[k][j]);
        }
      }
    }

    vector<bool> ans;
    for (auto &query : queries) {
      ans.push_back(dp[query[0]][query[1]]);
    }
    return ans;
  }

 public:

  vector<bool>
  checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries) {
    return floyd(numCourses, prerequisites, queries);
  }

};

int main() {

  vector<vector<int>> a = {{0, 1},
                           {1, 2},
                           {2, 3},
                           {3, 4}};
  vector<vector<int>> b = {{0, 4},
                           {4, 0},
                           {1, 3},
                           {3, 0}};

  Solution().checkIfPrerequisite(5, a, b);

  return 0;
}
