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
  vector<int> singleNumber(vector<int> &nums) {
    int all_xor = 0;
    for (const auto &item : nums) {
      all_xor ^= item;
    }
    all_xor = (all_xor == INT_MIN ? all_xor : all_xor & (-all_xor));

    int type1 = 0, type2 = 0;
    for (int num : nums) {
      if ((num & all_xor) == 0) {
        type1 ^= num;
      } else {
        type2 ^= num;
      }
    }
    return {type1, type2};
  }
};
