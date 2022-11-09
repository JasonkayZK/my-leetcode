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
#include <queue>
#include <sstream>
#include <list>
#include <set>
#include <functional>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <ctime>
#include <type_traits>
#include <cstdint>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:

  int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n));

    dp[0][0] = grid[0][0];
    for (int i = 1; i < m; ++i) {
      dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for (int i = 1; i < n; ++i) {
      dp[0][i] = dp[0][i - 1] + grid[0][i];
    }

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
      }
    }

    return dp[m - 1][n - 1];
  }

 private:

};

int main() {

  return 0;
}
