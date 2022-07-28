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

using namespace std;

class Solution {
/* DP */
 public:

  int climbStairs(int n) {
    if (n == 0 || n == 1) return 1;

    int first, second = 1, third = 1;
    for (int i = 2; i <= n; i++) {
      first = second;
      second = third;
      third = (first + second);
    }
    return third;
  }
};
