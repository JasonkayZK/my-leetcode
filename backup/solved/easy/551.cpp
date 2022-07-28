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
  bool checkRecord(string s) {
    int absents = 0, lates = 0;
    for (auto &ch : s) {
      if (ch == 'A') {
        absents++;
        if (absents >= 2) {
          return false;
        }
      }
      if (ch == 'L') {
        lates++;
        if (lates >= 3) {
          return false;
        }
      } else {
        lates = 0;
      }
    }
    return true;
  }
};
