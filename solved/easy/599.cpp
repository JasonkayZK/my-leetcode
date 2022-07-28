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

vector<string> split(const string &s, const char delimiter) {
  vector<string> tokens;
  string token;
  istringstream token_stream(s);
  while (getline(token_stream, token, delimiter)) {
    tokens.push_back(token);
  }
  return tokens;
}

class Solution {
 private:

 public:

  vector<string> findRestaurant(vector<string> &list1, vector<string> &list2) {
    vector<string> s{};
    vector<string> l{};
    unordered_map<string, int> m{};

    if (list1.size() < list2.size()) {
      s = list1;
      l = list2;
    } else {
      s = list2;
      l = list1;
    }

    for (int i = 0; i < s.size(); ++i) {
      m.emplace(s[i], i);
    }

    int minSum = INT_MAX;
    vector<string> res{};
    for (int i = 0; i < l.size(); ++i) {
      if (m.count(l[i]) > 0) {
        int idxSum = i + m[l[i]];

        if (idxSum < minSum) {
          res.clear();
          minSum = idxSum;
          res.push_back(l[i]);
        } else if (idxSum == minSum) {
          res.push_back(l[i]);
        }
      }
    }

    return res;
  }

};

int main() {

  return 0;
}
