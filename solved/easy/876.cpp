#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:

public:

    ListNode *middleNode(ListNode *head) {
        auto *scout = new ListNode;
        scout->next = head;

        ListNode *fast = scout, *slow = fast;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast != nullptr) slow = slow->next;
        return slow;
    }

};

int main() {

    return 0;
}
