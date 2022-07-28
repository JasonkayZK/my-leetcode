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
#include <set>
#include <random>

using namespace std;

using PII = pair<int, int>;
using LL = long long;
using PIC = pair<int, char>;

// Definition for a binary tree node.
class TreeNode {
 public:
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Definition for singly-linked list.
class ListNode {
 public:
  int val;
  ListNode *next;

  ListNode() : val(0), next(nullptr) {}

  ListNode(int x) : val(x), next(nullptr) {}

  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print_vec(vector<int> arr) {
  std::for_each(arr.begin(), arr.end(), [](const auto &i) { std::cout << i << " "; });
  cout << "\n";
}

void swap(vector<int> &nums, int i, int j) {
  int temp = nums[i];
  nums[i] = nums[j];
  nums[j] = temp;
}

class Solution {
 private:
  vector<int> visited;

  static bool isPowerOfTwo(int n) {
    return (n & (n - 1)) == 0;
  }

  bool backtrack(string &nums, int idx, int num) {
    if (idx == nums.length()) {
      return isPowerOfTwo(num);
    }

    for (int i = 0; i < nums.length(); ++i) {
      // 不能有前导零 || 已经使用过 || 重复的数字
      if ((num == 0 && nums[i] == '0') || visited[i] || (i > 0 && !visited[i - 1] && nums[i] == nums[i - 1])) {
        continue;
      }
      visited[i] = 1;
      if (backtrack(nums, idx + 1, num * 10 + nums[i] - '0')) {
        return true;
      }
      visited[i] = 0;
    }
    return false;
  }

 public:
  bool reorderedPowerOf2(int n) {
    string nums = to_string(n);
    sort(nums.begin(), nums.end());
    visited.resize(nums.length());
    return backtrack(nums, 0, 0);
  }
};
