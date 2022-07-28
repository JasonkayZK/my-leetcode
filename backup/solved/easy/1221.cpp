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

using PII = pair<int, int>;
using LL = long long;
using PIC = pair<int, char>;

class Solution {
 public:
  int balancedStringSplit(string s) {
    int res = 0, curCnt = 0;
    for (char i : s) {
      if ('R' == i) curCnt++;
      else curCnt--;
      if (curCnt == 0) res++;
    }
    return res;
  }
};
