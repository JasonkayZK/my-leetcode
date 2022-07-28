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
  int numSquares(int n) {
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; ++i) {
      int minn = INT_MAX;
      for (int j = 1; j * j <= i; ++j) {
        minn = min(minn, dp[i - j * j]);
      }
      dp[i] = minn + 1;
    }
    return dp[n];
  }
};
