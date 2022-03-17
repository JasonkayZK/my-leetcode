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

class Solution {
private:

    int maxOr = 0;
    int res = 0;

public:

    int countMaxOrSubsets(vector<int> &nums) {
        this->res = 0;
        maxOr = accumulate(nums.begin(), nums.end(), 0, bit_or<int>{});
        helper(nums, 0, 0);
        return res;
    }

    void helper(vector<int> &nums, int x, int cur) {
        int n = int(nums.size());
        if (cur == maxOr) {
            res += 1 << (n - x);
            return;
        }
        if (x == n) return;

        helper(nums, x + 1, cur); // not pick next
        helper(nums, x + 1, cur | nums[x]);
    }

};

int main() {

    return 0;
}
