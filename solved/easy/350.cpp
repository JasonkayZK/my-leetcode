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

using pii = pair<int, int>;
using ll = long long;
using pic = pair<int, char>;

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

void print_vec(const vector<int> &arr) {
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

class TrieTree {
 public:
  TrieTree() {
    this->children = vector<TrieTree *>(26, nullptr);
    this->isEnd = false;
  }

  void insert(const string &word) {
    TrieTree *node = this;
    for (const auto &item : word) {
      int idx = item - 'a';
      if (node->children[idx] == nullptr) {
        node->children[idx] = new TrieTree();
      }

      node = node->children[idx];
    }

    node->isEnd = true;
  }

  bool search(const string &word) {
    TrieTree *node = this;
    for (const auto &item : word) {
      int idx = item - 'a';
      if (node->children[idx] == nullptr) {
        return false;
      }
      node = node->children[idx];
    }
    return node->isEnd;
  }

 private:
  vector<TrieTree *> children;
  bool isEnd;
};

int dirs[9][2]{{0, 0},
               {1, 0},
               {-1, 0},
               {0, 1},
               {0, -1},
               {-1, -1},
               {-1, 1},
               {1, -1},
               {1, 1}};

/* Solution 1: HashMap
class Solution {
private:

public:

    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        vector<int> map1(1001, 0);
        vector<int> map2(1001, 0);

        for (const auto &item: nums1) {
            map1[item]++;
        }
        for (const auto &item: nums2) {
            map2[item]++;
        }

        vector<int> res;
        for (int i = 0; i < 1001; ++i) {
            int cnt = min(map1[i], map2[i]);
            for (int j = 0; j < cnt; ++j) {
                res.push_back(i);
            }
        }
        return res;
    }
};
 */

/* Solution 2: Sort + Two Pointer */
class Solution {
 private:

 public:

  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());

    vector<int> res;
    int l = 0, r = 0, m = nums1.size(), n = nums2.size();
    while (l < m && r < n) {
      if (nums1[l] < nums2[r]) {
        l += 1;
      } else if (nums1[l] == nums2[r]) {
        res.push_back(nums1[l]);
        l += 1;
        r += 1;
      } else {
        r += 1;
      }
    }
    return res;
  }
};

int main() {

  vector<int> l = {4, 9, 5};
  vector<int> a = {9, 4, 9, 8, 4};
  print_vec(Solution().intersect(l, a));

  return 0;
}
