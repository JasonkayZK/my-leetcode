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

    for (const auto &item: vec) {
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
        for (const auto &item: word) {
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
        for (const auto &item: word) {
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

/* Solution 1: Recursive
class Solution {
private:
    unordered_set<int> s;

public:

    bool findTarget(TreeNode* root, int k) {
        if (root == nullptr) return false;
        if (s.count(k - root->val) > 0) return true;
        s.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }

};
*/

/* Solution 2: Two pointer */
class Solution {
private:

    TreeNode *getLeft(stack<TreeNode *> &stk) {
        TreeNode *root = stk.top();
        stk.pop();
        TreeNode *node = root->right;
        while (node != nullptr) {
            stk.push(node);
            node = node->left;
        }
        return root;
    }

    TreeNode *getRight(stack<TreeNode *> &stk) {
        TreeNode *root = stk.top();
        stk.pop();
        TreeNode *node = root->left;
        while (node != nullptr) {
            stk.push(node);
            node = node->right;
        }
        return root;
    }

public:

    bool findTarget(TreeNode *root, int k) {
        if (root == nullptr) return false;
        auto left = root, right = root;
        stack<TreeNode *> leftStk, rightStk;

        leftStk.push(left);
        while (left->left != nullptr) {
            leftStk.push(left->left);
            left = left->left;
        }
        rightStk.push(right);
        while (right->right != nullptr) {
            rightStk.push(right->right);
            right = right->right;
        }

        while (left != right) {
            if (left->val + right->val == k) {
                return true;
            }
            if (left->val + right->val < k) {
                left = getLeft(leftStk);
            } else {
                right = getRight(rightStk);
            }
        }

        return false;
    }

};


int main() {

    return 0;
}
