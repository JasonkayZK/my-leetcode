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
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    int n = candidates.size();
    if (n <= 0)
      return {};

    sort(candidates.begin(), candidates.end());

    vector<vector<int>> res;
    vector<int> cur;
    dfs_helper(candidates, res, cur, 0, 0, target, n);
    return res;
  }

  void dfs_helper(const vector<int> &candidates, vector<vector<int>> &res,
                  vector<int> &cur_res, int cur_idx, int cur, const int target,
                  const int n) {

    if (cur > target) {
      return;
    }

    if (cur == target) {
      res.push_back(cur_res);
      return;
    }

    for (int i = cur_idx; i < n; ++i) {
      if (cur + candidates[i] <= target) {
        cur_res.push_back(candidates[i]);
        dfs_helper(candidates, res, cur_res, i, cur + candidates[i], target, n);
        cur_res.pop_back();
      }
    }
  }
};

int main() { return 0; }
