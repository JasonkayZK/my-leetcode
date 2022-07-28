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

  static ListNode *build_node(const vector<int> &vec);

  void print() {

    auto head = this;

    std::cout << "[";

    while (head) {
      std::cout << head->val << ", ";
      head = head->next;
    }

    std::cout << "]" << std::endl;
  }

};

ListNode *ListNode::build_node(const vector<int> &vec) {

  auto *dummy = new ListNode(0);
  auto res = dummy;

  for (const auto &item : vec) {
    res->next = new ListNode(item);
    res = res->next;
  }

  return dummy->next;
}

// Definition for a Node.
class Node {
 public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val) {
    val = _val;
  }

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
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

/* Method 1: BFS
class Solution {
private:

public:

    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;

        stack<TreeNode *> stkP{};
        stack<TreeNode *> stkQ{};
        stkP.push(p);
        stkQ.push(q);
        while (!stkP.empty() && !stkQ.empty()) {
            auto curP = stkP.top();
            stkP.pop();
            auto curQ = stkQ.top();
            stkQ.pop();

            if (curP->left != nullptr && curQ->left != nullptr) {
                stkP.push(curP->left);
                stkQ.push(curQ->left);
            } else if ((curP->left != nullptr && curQ->left == nullptr) ||
                       (curP->left == nullptr && curQ->left != nullptr)) {
                return false;
            }

            if (curP->val != curQ->val) {
                return false;
            }

            if (curP->right != nullptr && curQ->right != nullptr) {
                stkP.push(curP->right);
                stkQ.push(curQ->right);
            } else if ((curP->right != nullptr && curQ->right == nullptr) ||
                       (curP->right == nullptr && curQ->right != nullptr)) {
                return false;
            }
        }

        while (!stkP.empty() && !stkQ.empty()) {
            if (stkP.top()->val != stkQ.top()->val) {
                return false;
            }
            stkP.pop();
            stkQ.pop();
        }

        return stkP.empty() && stkQ.empty();
    }

};
*/

/* Solution 2: Recursive */
class Solution {
 private:

 public:

  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr) return true;
    if (p == nullptr || q == nullptr)return false;

    if (p->val != q->val)return false;
    else return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }

};

int main() {

  auto p = new TreeNode(1);
  p->left = new TreeNode(2);

  auto q = new TreeNode(1);
  q->right = new TreeNode(2);

  std::cout << Solution{}.isSameTree(p, q);

  return 0;
}
