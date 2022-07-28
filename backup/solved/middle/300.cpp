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
#include <random>

using namespace std;

class Solution {
 public:
  /* Method 1：DP
  int lengthOfLIS(vector<int> &nums) {
      int len = nums.size();
      if (len <= 0) return 0;

      vector<int> dp(len, 0);
      for (int i = 0; i < len; ++i) {
          dp[i] = 1;
          for (int j = 0; j < i; ++j) {
              if (nums[j] < nums[i]) {
                  dp[i] = max(dp[i], dp[j] + 1);
              }
          }
      }
      return *max_element(dp.begin(), dp.end());
  }
   */

  /* Method 2: Greedy + Binary Search */
  int lengthOfLIS(vector<int> &nums) {
    int len = nums.size(), curLen = 1;
    if (len <= 0) return 0;

    vector<int> d(len + 1, 0);
    d[curLen] = nums[0];
    for (int i = 0; i < len; ++i) {
      if (nums[i] > d[curLen]) {
        d[++curLen] = nums[i];
        continue;
      }

      // 如果找不到说明所有的数都比 nums[i] 大，此时要更新 d[1]，所以这里将 pos 设为 0
      int l = 1, r = curLen, pos = 0;
      while (l <= r) {
        int mid = l + (r - l) / 2;
        if (d[mid] < nums[i]) {
          pos = mid;
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
      d[pos + 1] = nums[i];
    }
    return curLen;
  }
};
