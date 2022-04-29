#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:

public:

    int projectionArea(vector<vector<int>> &grid) {
        int res1 = 0, res2 = 0, res3 = 0;

        int n = int(grid.size());
        for (int i = 0; i < n; ++i) {
            int cur2_max = 0, cur3_max = 0;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) res1++;
                cur2_max = max(cur2_max, grid[i][j]);
                cur3_max = max(cur3_max, grid[j][i]);
            }
            res2 += cur2_max;
            res3 += cur3_max;
        }

        return res1 + res2 + res3;
    }

};

int main() {

    return 0;
}
