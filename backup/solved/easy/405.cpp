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
  const string hex = "0123456789abcdef";

  string toHex(int num) {
    if (num == 0) return "0";
    string ans = "";
    while (num && ans.size() < 8) {
      ans = hex[num & 0xf] + ans;
      num >>= 4;
    }
    return ans;
  }
};
