#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <memory>

using namespace std;

class Solution {
 public:
  int totalHammingDistance(vector<int> &nums) {
    int res = 0, len = nums.size();
    for (int i = 0; i < 30; ++i) {
      int cur = 0;
      for (int val : nums) {
        cur += (val >> i) & 1;
      }
      res += cur * (len - cur);
    }
    return res;
  }
};
