#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
private:

public:

    int maxDepth(Node *root) {
        if (root == nullptr) return 0;

        int cur_max = 0;
        for (const auto &item: root->children) {
            cur_max = max(cur_max, maxDepth(item));
        }
        return cur_max + 1;
    }

};

int main() {


    return 0;
}
