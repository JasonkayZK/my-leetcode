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

  bool validUtf8(vector<int> &data) {
    int byte_cnt = 0;

    for (const auto &item : data) {
      if (byte_cnt > 0) {
        if (item >> 6 != 2) return false;
        else byte_cnt--;
      } else if (item >> 7 == 0) {
        byte_cnt = 0;
      } else if (item >> 5 == 0b110) {
        byte_cnt = 1;
      } else if (item >> 4 == 0b1110) {
        byte_cnt = 2;
      } else if (item >> 3 == 0b11110) {
        byte_cnt = 3;
      } else {
        return false;
      }
    }

    return byte_cnt == 0;
  }

};

int main() {

  return 0;
}
