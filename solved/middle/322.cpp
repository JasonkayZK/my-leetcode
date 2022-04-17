#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

/* Method 1: DP */
class Solution {
private:

public:
    int coinChange(vector<int> &coins, int amount) {
        if (amount <= 0) return 0;
        int n = int(coins.size());
        if (n <= 0) return -1;

        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < n; ++j) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};

int main() {

    return 0;
}
