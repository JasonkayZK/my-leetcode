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
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;

    if (root == nullptr)
      return {{}};

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int cur_n = q.size();
      vector<int> cur;
      for (int i = 0; i < cur_n; ++i) {
        auto cur_node = q.front();
        q.pop();

        cur.push_back(cur_node->val);
        if (cur_node->left != nullptr)
          q.push(cur_node->left);
        if (cur_node->right != nullptr)
          q.push(cur_node->right);
      }
      res.push_back(cur);
    }

    return res;
  }
};

int main() { return 0; }
