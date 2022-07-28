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

using namespace std;

class Solution {
 public:
  int minMoves(vector<int> &nums) {
    int min = *min_element(nums.begin(), nums.end());
    int res = 0;
    for (const auto &item : nums) {
      res += item - min;
    }
    return res;
  }
};
