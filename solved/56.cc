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
  vector<vector<int>> merge(vector<vector<int>> &intervals) {

    int n = intervals.size();
    if (n <= 0)
      return {};

    sort(intervals.begin(), intervals.end(),
         [](vector<int> &x, vector<int> &y) {
           if (x[0] != y[0]) {
             return x[0] < y[0];
           } else {
             return x[1] < y[1];
           }
         });

    vector<vector<int>> res;
    int l = intervals[0][0], r = intervals[0][1];
    for (int i = 1; i < n; ++i) {
      if (intervals[i][0] > r) {
        res.push_back({l, r});
        l = intervals[i][0], r = intervals[i][1];
      } else {
        r = max(r, intervals[i][1]);
      }
    }

    res.push_back({l, r});

    return res;
  }

private:
};

int main() { return 0; }
