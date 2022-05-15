#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
public:

    int maximumWhiteTiles(vector<vector<int>> &tiles, int carpetLen) {
        int n = int(tiles.size());
        if (n <= 0) return 0;

        sort(tiles.begin(), tiles.end());

        long long cur = 0, res = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < n && tiles[j][1] + 1 - tiles[i][0] <= carpetLen) {
                cur += tiles[j][1] - tiles[j][0] + 1;
                j++;
            }
            // 毯子无法完全覆盖第 j 组瓷砖
            if (j < tiles.size()) res = max(res, cur + max(0, tiles[i][0] + carpetLen - tiles[j][0]));
                // 毯子可以完全覆盖第 j 组瓷砖
            else res = max(res, cur);
            cur -= tiles[i][1] - tiles[i][0] + 1;
        }

        return res;
    }

private:


};

int main() {


    return 0;
}
