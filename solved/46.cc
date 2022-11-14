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
  vector<vector<int>> permute(vector<int> &&nums) {
    int n = nums.size();
    vector<vector<int>> res;
    dfs_helper(nums, res, n, 0);
    return res;
  }

private:
  void dfs_helper(vector<int> &nums, vector<vector<int>> &res,
                  int n, int i) {

    if (i >= n) {
      res.push_back(nums);
      return;
    }

    for (int j = i; j < n; ++j) {
      swap(nums, i, j);
      dfs_helper(nums, res, n, i + 1);
      swap(nums, i, j);
    }
  }

  void swap(vector<int> &arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
};

int main() {

  Solution().permute({1, 2, 3});

  return 0;
}
