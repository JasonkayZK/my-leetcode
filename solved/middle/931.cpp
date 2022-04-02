#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"

class Solution {
private:

public:

    int minFallingPathSum(vector<vector<int>> &matrix) {
        int n = int(matrix.size());
        if (n <= 0) return 0;
        if (n == 1) {
            int sum = 0;
            for (const auto &item : matrix) {
                sum += std::accumulate(item.begin(), item.end(), 0);
            }
            return sum;
        }

        vector<int> dp(n);
        for (int i = 0; i < n; ++i) { // init dp arr
            dp[i] = matrix[0][i];
        }

        for (int i = 1; i < n; ++i) { // 1~n-1 row to go
            vector<int> temp(n);
            for (int j = 0; j < n; ++j) {
                if (j == 0) {
                    temp[j] = min(dp[0], dp[1]) + matrix[i][j];
                } else if (j == n - 1) {
                    temp[j] = min(dp[n - 2], dp[n - 1]) + matrix[i][j];
                } else {
                    temp[j] = min(min(dp[j - 1], dp[j]), dp[j + 1]) + matrix[i][j];
                }
            }
            dp = temp;
        }

        return *std::min_element(dp.begin(), dp.end());
    }

};

int main() {

    return 0;
}
