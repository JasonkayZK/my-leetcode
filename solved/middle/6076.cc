#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
public:

    int minimumLines(vector<vector<int>> &stockPrices) {
        sort(stockPrices.begin(), stockPrices.end(), [](const vector<int> &x, const vector<int> &y) {
            return x[0] < y[0];
        });

        int n = int(stockPrices.size()), res = 1;
        if (n <= 1) return 0;
        for (int i = 2; i < n; ++i) {
            int x1 = stockPrices[i][0] - stockPrices[i - 1][0], y1 = stockPrices[i][1] - stockPrices[i - 1][1];
            int x2 = stockPrices[i - 1][0] - stockPrices[i - 2][0], y2 = stockPrices[i - 1][1] - stockPrices[i - 2][1];
            if (x1 * y2 != y1 * x2) res++;
        }

        return res;
    }

private:


};

int main() {

    vector<vector<int>> l = {
            {3, 4},
            {1, 2},
            {7, 8},
            {2, 3}
    };
    Solution().minimumLines(l);

    return 0;
}
