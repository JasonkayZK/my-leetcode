#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

 public:

  void deleteNode(ListNode *node) {
    if (node == nullptr) return;
    if (node->next == nullptr) node = nullptr;
    else {
      node->val = node->next->val;
      node->next = node->next->next;
    }
  }

};

int main() {

  return 0;
}
