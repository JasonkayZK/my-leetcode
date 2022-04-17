#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:

public:

    int giveGem(vector<int> &gem, vector<vector<int>> &operations) {

        for (const auto &item: operations) {
            int give = gem[item[0]] / 2;
            gem[item[0]] -= give;
            gem[item[1]] += give;
        }

        int x_min = INT_MAX, x_max = 0;
        for (const auto &item: gem) {
            x_min = min(x_min, item);
            x_max = max(x_max, item);
        }
        return x_max - x_min;
    }

};

int main() {

    return 0;
}
