#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:
    int rotateMap[4][2] = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}
    };

    bool validDir(const int x, const int n) {
        return x >= 0 && x < n;
    }

public:

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res = vector(n, vector<int>(n, 0));

        int i = 0, j = -1, cur_dir = 0, bound = n * n;
        for (int k = 1; k <= bound; ++k) {
            int next_i = i + rotateMap[cur_dir][0], next_j = j + rotateMap[cur_dir][1];
            if (!validDir(next_i, n) || !validDir(next_j, n) || res[next_i][next_j] != 0) {
                cur_dir = (cur_dir + 1) % 4;
                k--;
                continue;
            }

            i = next_i, j = next_j;
            res[i][j] = k;
        }

        return res;
    }

};

int main() {

    Solution().generateMatrix(3);

    return 0;
}
