#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"

class Solution {
private:

public:
    ListNode *removeElements(ListNode *head, int val) {
        auto *scott = new ListNode();
        scott->next = head;

        auto cur = scott;
        while (cur != nullptr && cur->next != nullptr) {
            while (cur->next != nullptr && cur->next->val == val) cur->next = cur->next->next;
            cur = cur->next;
        }

        return scott->next;
    }
};

int main() {


    return 0;
}
