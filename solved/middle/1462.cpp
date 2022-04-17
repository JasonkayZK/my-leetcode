#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:

    vector<bool> bfs(int numCourses, vector <vector<int>> &prerequisites, vector <vector<int>> &queries) {
        vector <vector<int>> graph(numCourses);

        // init graph
        for (const auto &item: prerequisites) {
            graph[item[0]].push_back(item[1]);
        }

        // update path
        vector <vector<bool>> can_reach(numCourses, vector<bool>(numCourses, false));
        for (int i = 0; i < numCourses; ++i) {
            queue<int> q;
            q.emplace(i);

            while (!q.empty()) {
                int from = q.front();
                q.pop();

                for (const auto &to: graph[from]) {
                    if (!can_reach[i][to]) {
                        can_reach[i][to] = true;
                        q.emplace(to);
                    }
                }
            }
        }

        // build answer
        int n = queries.size();
        vector<bool> res(n);
        for (int i = 0; i < n; ++i) {
            res[i] = can_reach[queries[i][0]][queries[i][1]];
        }

        return res;
    }

    vector<bool> dfs(int numCourses, vector <vector<int>> &prerequisites, vector <vector<int>> &queries) {
        vector<vector<int>> graph(numCourses);
        vector<vector<int>> memo(numCourses, vector<int>(numCourses, 0));

        // init graph
        for (const auto &item: prerequisites) {
            graph[item[0]].push_back(item[1]);
            memo[item[0]][item[1]] = 1;
        }

        int n = int(queries.size());
        vector<bool> res(n);
        for (int i = 0; i < n; ++i) {
            res[i] = dfs_helper(graph, queries[i][0], queries[i][1], memo);
        }
        return res;
    }

    bool dfs_helper(const vector <vector<int>> &graph, int from, int to, vector <vector<int>> &memo) {
        if (memo[from][to] == 1) return true;
        if (memo[from][to] == -1) return false;

        for (const auto &middle: graph[from]) {
            if (dfs_helper(graph, middle, to, memo)) {
                memo[from][to] = 1;
                return true;
            }
        }

        memo[from][to] = -1;
        return false;
    }

    vector<bool> floyd(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
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
    checkIfPrerequisite(int numCourses, vector <vector<int>> &prerequisites, vector <vector<int>> &queries) {
        return floyd(numCourses, prerequisites, queries);
    }

};

int main() {

    vector <vector<int>> a = {{0, 1},
                              {1, 2},
                              {2, 3},
                              {3, 4}};
    vector <vector<int>> b = {{0, 4},
                              {4, 0},
                              {1, 3},
                              {3, 0}};

    Solution().checkIfPrerequisite(5, a, b);

    return 0;
}
