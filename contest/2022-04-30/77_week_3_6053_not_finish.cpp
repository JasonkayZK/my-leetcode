#include "../../utils/utils.h"
#include "../../data_structure/list.h"
#include "../../data_structure/tree.h"
#include "../../data_structure/trie.h"
#include "../../data_structure/segment_tree.h"
#include "../../data_structure/union_find.h"

class Solution {
private:

    void traverse(unordered_set<int> &graph, const unordered_set<int> &wall_map,
                  int x, int y, int m, int n) {

        int i;
        for (i = x; i >= 0; --i) { // up
            int cur = i * n + y;
            if (wall_map.count(cur) > 0) break;
            graph.emplace(cur);
        }
        for (i = x + 1; i < m; ++i) { // down
            int cur = i * n + y;
            if (wall_map.count(cur) > 0) break;
            graph.emplace(cur);
        }
        for (i = y; i >= 0; --i) { // left
            int cur = x * n + i;
            if (wall_map.count(cur) > 0) break;
            graph.emplace(cur);
        }
        for (i = y + 1; i < n; ++i) { // left
            int cur = x * n + i;
            if (wall_map.count(cur) > 0) break;
            graph.emplace(cur);
        }

    }

public:

    int countUnguarded(int m, int n, vector<vector<int>> &&guards, vector<vector<int>> &&walls) {
        if (m <= 0 || n <= 0) return 0;

        // wall map
        unordered_set<int> graph;
        unordered_set<int> wall_map;
        for (const auto &item: walls) {
            int cur = item[0] * n + item[1];
            wall_map.emplace(cur);
            graph.emplace(cur);
        }

        for (const auto &item: guards) {
            traverse(graph, wall_map, item[0], item[1], m, n);
        }

        return m * n - int(graph.size());
    }

};

int main() {

    vector<vector<int>> l = {};

    Solution().countUnguarded(4, 6,
                              {{0, 0},
                               {1, 1},
                               {2, 3}},
                              {{0, 1},
                               {2, 2},
                               {1, 4}});

    return 0;
}
