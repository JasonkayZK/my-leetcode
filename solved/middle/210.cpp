#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:

public:

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> in_degree(numCourses);

        // init graph
        for (const auto &item: prerequisites) {
            adj[item[1]].push_back(item[0]);
            in_degree[item[0]]++;
        }

        // init topological queue
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (in_degree[i] == 0) {
                q.emplace(i);
            }
        }

        // topological sort
        vector<int> res;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            res.push_back(cur);

            for (auto &item : adj[cur]) {
                in_degree[item]--;
                if (in_degree[item] == 0) {
                    q.emplace(item);
                }
            }
        }

        return res.size() == numCourses ? res : vector<int>();
    }

};

int main() {

    return 0;
}
