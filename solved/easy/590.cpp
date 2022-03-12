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

/* Solution 1: Recursive
class Solution {
private:

    vector<int> res;

    void helper(const Node *root) {
        if (root == nullptr) {
            return;
        }

        for (int i = 0; i < root->children.size(); ++i) {
            helper(root->children[i]);
        }

        res.push_back(root->val);
    }

public:
    vector<int> postorder(Node *root) {
        res = {};
        helper(root);
        return res;
    }

};
*/

/* Solution 2: Stack */
class Solution {
private:

public:
    vector<int> postorder(Node *root) {
        vector<int> res = {};

        if (root == nullptr) return {};

        stack<Node *> stk{};
        stk.push(root);

        while (!stk.empty()) {
            auto node = stk.top();
            stk.pop();

            res.push_back(node->val);
            vector<Node *> chs = node->children;
            if (!chs.empty()) {
                for (int i = 0, size = chs.size(); i < size; i++) {
                    auto n = chs[i];
                    if (n) stk.push(n);
                }
            }
        }
        reverse(res.begin(), res.end());

        return res;
    }
};
