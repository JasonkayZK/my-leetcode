#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:

public:

    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
    }

};

int main() {

    return 0;
}
