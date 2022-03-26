//
// Created by JasonkayZK on 2022/3/26.
//

#include "list.h"
#include "../utils/utils.h"

ListNode *ListNode::build_node(const vector<int> &vec) {

    auto *dummy = new ListNode(0);
    auto res = dummy;

    for (const auto &item: vec) {
        res->next = new ListNode(item);
        res = res->next;
    }

    return dummy->next;
}
