#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

/* Method 1: DFS
class Solution {
private:

    void dfs_helper(vector<vector<int>>& isConnected, int from, vector<bool> & visited, int n) {
        if (visited[from]) return;

        visited[from] = true;
        for (int to = 0; to < n; ++to) {
            if (visited[to]) continue;

            if (isConnected[from][to] == 1) { // mark next
                dfs_helper(isConnected, to, visited, n);
            }
        }
    }

public:

    int findCircleNum(vector<vector<int>>& isConnected) {
        if (isConnected.empty() || isConnected[0].empty()) return 0;
        int n = int(isConnected.size());
        if (n <= 1) return n;

        vector<bool> visited(n, false);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            dfs_helper(isConnected, i, visited, n);
            res++;
        }
        return res;
    }

};
*/

/* Method 2: BFS
class Solution {
private:

public:

    int findCircleNum(vector<vector<int>>& isConnected) {
        if (isConnected.empty() || isConnected[0].empty()) return 0;
        int n = int(isConnected.size());
        if (n <= 1) return n;

        vector<bool> visited(n, false);
        int res = 0;
        queue<int> q;
        for (int from = 0; from < n; ++from) {
            if (visited[from]) continue;
            q.emplace(from);
            visited[from] = true;
            res++;

            while (!q.empty()) { // bfs to mark
                int cur = q.front();
                q.pop();
                for (int to = 0; to < n; ++to) {
                    if (visited[to] || isConnected[cur][to] == 0) continue;
                    q.emplace(to);
                    visited[to] = true;
                }
            }
        }

        return res;
    }

};
*/

/* Method 3: Union Find */
class Solution {
private:

public:

    int findCircleNum(vector<vector<int>> &isConnected) {
        if (isConnected.empty() || isConnected[0].empty()) return 0;
        int n = int(isConnected.size());
        if (n <= 1) return n;

        UnionFind<int> uf{-1};
        for (int i = 0; i < isConnected.size(); i++) {
            uf.add(i);
            for (int j = 0; j < i; j++) {
                if (isConnected[i][j]) {
                    uf.merge(i, j);
                }
            }
        }

        return uf.get_strongly_connected_component_cnt();
    }

};

int main() {
    int a = 666;
    vector<int> b({1, 2, 3});
    string c = "hello world";

    // after
    debug(a, b, c);  // a=666, b=[ 1, 2, 3, ], c=hello world

    return 0;
}
