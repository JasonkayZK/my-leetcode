#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <memory>
#include <cmath>
#include <numeric>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
/* Method 1: Math
    bool stoneGame(vector<int>& piles) {
        return true;
    }
*/

/* Method 2: DP */
    bool stoneGame(vector<int>& piles) {
        int len = piles.size();
        int dp[len][len];
        for (int i = 0; i < len; i++) {
            dp[i][i] = piles[i];
        }

        for (int i = len - 2; i >= 0; i--) {
            for (int j = i + 1; j < len; j++) {
                dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
            }
        }
        return dp[0][len - 1] > 0;
    }
};
