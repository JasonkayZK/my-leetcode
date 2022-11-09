2#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

/* Method 1: Topological Sort
class Solution {
private:

public:

    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        if (n <= 1) return {0};

        // build graph
        vector<int> degrees(n);
        vector<vector<int>> adj(n);
        for (const auto &item: edges) {
            adj[item[0]].push_back(item[1]);
            adj[item[1]].push_back(item[0]);
            degrees[item[0]]++;
            degrees[item[1]]++;
        }

        // start with the leaf node
        queue<int> qu;
        for (int i = 0; i < n; ++i) {
            if (degrees[i] == 1) {
                qu.emplace(i);
            }
        }

        // remove util one or two node is left
        int remainNodes = n;
        while (remainNodes > 2) {
            int sz = int(qu.size());
            remainNodes -= sz;
            for (int i = 0; i < sz; ++i) {
                // remove cur node
                int curr = qu.front();
                qu.pop();
                // decrease degree for adjacent node
                for (auto &item: adj[curr]) {
                    --degrees[item];
                    if (degrees[item] == 1) {
                        qu.emplace(item);
                    }
                }
            }
        }

        // The last one or two is the answer
        vector<int> res;
        while (!qu.empty()) {
            res.push_back(qu.front());
            qu.pop();
        }
        return res;
    }

};
*/

/* Method 2: Tree dp */
class Solution {
 private:

 public:

  vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {

  }

};

int main() {

  vector<vector<int>> l = {{1, 0},
                           {1, 2},
                           {1, 3}};
  Solution().findMinHeightTrees(4, l);

  return 0;
}

