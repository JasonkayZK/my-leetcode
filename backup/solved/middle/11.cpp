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
#include <set>
#include <random>

using namespace std;

class Solution {
 public:
  int maxArea(vector<int> &height) {
    int len = height.size(), l = 0, r = len - 1, max = 0;
    while (l < r) {
      int size = (r - l) * min(height[l], height[r]);
      max = size > max ? size : max;
      if (height[l] < height[r]) l++;
      else r--;
    }
    return max;
  }
};
