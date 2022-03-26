//
// Created by JasonkayZK on 2022/3/26.
//

#ifndef MY_LEETCODE_LIST_H
#define MY_LEETCODE_LIST_H

#include <utility>

#include "../utils/utils.h"

using namespace std;

// Definition for singly-linked list.
class ListNode {
public:
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}

    static ListNode *build_node(const std::vector<int> &vec);

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



// Definition for a Node.
class Node {
public:
    int val{};
    std::vector<Node *> children;

    Node() = default;

    explicit Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node *> _children) {
        val = _val;
        children = std::move(_children);
    }
};

#endif //MY_LEETCODE_LIST_H
