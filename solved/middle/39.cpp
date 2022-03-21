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

/* Solution 1: dp */
class Solution {
private:

public:

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<vector<int>>> res(target + 1);
        vector<int> dp(target + 1);

        res[0] = {{}};
        dp[0] = 1;

        for (const auto &item: candidates) {
            for (int i = item; i <= target; ++i) {
                dp[i] += dp[i - item];

                if (dp[i - item] > 0) { // if answer exist, add to res
                    for (auto &cur: res[i - item]) {
                        vector<int> newVec = {cur};
                        newVec.push_back(item);
                        res[i].push_back(newVec);
                    }
                }
            }
        }

        return res[target];
    }
};


/* Solution 2: Backtrace
class Solution {
private:

    vector<vector<int>> res;

public:

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {

        res = {};
        vector<int> curRes = {};
        helper(candidates, target, 0, 0, curRes);
        return res;
    }

    void helper(const vector<int> &candidates, int target, int curSum, int idx, vector<int> &curRes) {
        if (idx >= candidates.size() || curSum > target) return;
        if (curSum == target) {
            res.push_back(curRes);
            return;
        }

        curRes.push_back(candidates[idx]);
        helper(candidates, target, curSum + candidates[idx], idx, curRes);
        curRes.pop_back();

        helper(candidates, target, curSum, idx + 1, curRes);
    }
};
*/

int main() {

    vector<int> list = {2, 3, 5};

    auto res = Solution().combinationSum(list, 8);
    for (const auto &item: res) {
        print_vec(item);
    }

    return 0;
}

