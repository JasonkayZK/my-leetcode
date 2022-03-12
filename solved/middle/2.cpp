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

ListNode* ListNode::build_node(const vector<int> &vec) {

    auto *dummy = new ListNode(0);
    auto res = dummy;

    for (const auto &item: vec) {
        res->next = new ListNode(item);
        res = res->next;
    }

    return dummy->next;
}

class Solution {
private:

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        auto *dummy = new ListNode(0);
        auto cur = dummy;
        int carry = 0;

        while (l1 || l2) {
            int x = l1 != nullptr ? l1->val : 0;
            int y = l2 != nullptr ? l2->val : 0;
            int val = x + y + carry;
            carry = val > 9 ? 1 : 0;
            val = val % 10;

            cur->next = new ListNode(val);

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;

            cur = cur->next;
        }

        if (carry != 0) {
            cur->next = new ListNode(1);
        }

        return dummy->next;
    }
};

int main() {

    auto list = ListNode::build_node({1, 2, 3});

    list->print();

    return 0;
}
