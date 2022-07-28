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
/* Method 1: Binary Search */
  int guessNumber(int n) {
    int left = 1, right = n, mid, guessRes;

    while (left < right) {
      mid = left + (right - left) / 2;
      guessRes = guess(mid);
      if (guessRes == 0) {
        return mid;
      } else if (guessRes < 0) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
};
