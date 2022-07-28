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
  int firstBadVersion(int n) {
    int left = 1, right = n;

    while (left < right) {
      int mid = (right - left) / 2 + left;
      if (isBadVersion(mid)) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
};
