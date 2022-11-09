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
#include <sstream>
#include <list>
#include <set>
#include <functional>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <ctime>
#include <type_traits>
#include <cstdint>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:

  int lengthOfLongestSubstring(string s) {
    int c_map[256];
    fill(c_map, c_map + 256, -1);
    int n = s.size();

    if (n <= 1) return n;
    if (n == 2) return s[0] == s[1] ? 1 : 2;

    int res = 1, l = 0, r = 1;
    c_map[s[0]] = 0;
    while (r < n) {
      if (c_map[s[r]] >= 0) {
        l = max(c_map[s[r]] + 1, l);
        c_map[s[r]] = r;
      } else {
        c_map[s[r]] = r;
      }
      res = max(res, r - l + 1);
      ++r;
    }
    return res;
  }

 private:

};

int main() {

  Solution().lengthOfLongestSubstring("abba");

  return 0;
}
