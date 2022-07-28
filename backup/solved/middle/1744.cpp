#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <memory>
#include <cmath>
#include <numeric>
#include <stack>
#include <unordered_set>

using namespace std;

using PII = pair<int, int>;
using LL = long long;

class Solution {
 private:

/* 前缀和 */
 public:
  vector<bool> canEat(vector<int> &candiesCount, vector<vector<int>> &queries) {
    int n = candiesCount.size();

    // 前缀和
    vector<LL> sum(n);
    sum[0] = candiesCount[0];
    for (int i = 1; i < n; ++i) {
      sum[i] = sum[i - 1] + candiesCount[i];
    }

    vector<bool> ans;
    for (const auto &q : queries) {
      int favoriteType = q[0], favoriteDay = q[1], dailyCap = q[2];

      LL min1 = favoriteDay + 1;
      LL max1 = (LL) (favoriteDay + 1) * dailyCap;
      LL min2 = (favoriteType == 0 ? 1 : sum[favoriteType - 1] + 1);
      LL max2 = sum[favoriteType];

      ans.push_back(!(min1 > max2 || max1 < min2));
    }
    return ans;
  }
};
