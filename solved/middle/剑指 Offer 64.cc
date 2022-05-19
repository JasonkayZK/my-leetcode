#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
public:

    int sumNums(int n) {
        if (n == 1) return 1;
        return n + sumNums(n - 1);
    }

private:


};

int main() {


    return 0;
}
