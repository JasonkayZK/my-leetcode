#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"

class Solution {
private:

public:

    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n > 0) {
            res += (n & 1) == 1;
            n >>= 1;
        }
        return res;
    }

};

int main() {


    return 0;
}
