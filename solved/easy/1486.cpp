#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:

    int sumXor(int x) { // calculate 1^2^.,,^x
        if (x % 4 == 0) return x;
        if (x % 4 == 1) return 1;
        if (x % 4 == 2) return x + 1;
        return 0;
    }

public:

    int xorOperation(int n, int start) {
        int s = start >> 1, e = n & start & 1;
        int ret = sumXor(s - 1) ^ sumXor(s + n - 1);
        return ret << 1 | e;
    }

};

int main() {

    return 0;
}
