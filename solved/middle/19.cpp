#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:

    int getLength(ListNode *head) {
        int res = 0;
        while (head != nullptr) {
            res++;
            head = head->next;
        }
        return res;
    }

public:

    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *scout = new ListNode(0, head);
        int len = getLength(head);

        ListNode* cur = scout;
        for (int i = 1; i < len - n + 1; ++i) { // find prev node
            cur = cur->next;
        }
        cur->next = cur->next->next; // remove node

        ListNode *res = scout->next;
        delete(scout);
        return res;
    }

};

int main() {

    return 0;
}
