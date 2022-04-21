#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:

public:

    bool isPalindrome(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return true;

        ListNode *fast = head, *slow = head, *prev = nullptr;

        // find middle node as slow, while reverse list
        while (fast != nullptr && fast->next != nullptr) {
            ListNode *temp = slow;

            // move next
            slow = slow->next;
            fast = fast->next->next;

            // reverse list
            temp->next = prev;
            prev = temp;
        }

        // odd length linked-list
        if (fast != nullptr) slow = slow->next;

        // check palindrome
        while (slow != nullptr) {
            if (prev->val != slow->val) {
                return false;
            }
            slow = slow->next;
            prev = prev->next;
        }
        return true;
    }
};

int main() {

    ListNode *l = new ListNode(1);
    l->next = new ListNode(2);
    l->next->next = new ListNode(2);
    l->next->next->next = new ListNode(1);

    Solution().isPalindrome(l);

    return 0;
}
