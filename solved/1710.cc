#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:

  int maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(), [](vector<int> &x, vector<int> &y) {
      return x[1] > y[1];
    });

    int res = 0;
    for (const auto &item : boxTypes) {
      if (item[0] < truckSize) {
        res += item[0] * item[1];
        truckSize -= item[0];
      } else {
        res += truckSize * item[1];
        break;
      }
    }
    return res;
  }

};

int main() { return 0; }
