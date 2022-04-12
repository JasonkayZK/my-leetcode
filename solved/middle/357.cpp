#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:

public:

    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        else if (n == 1) return 10;

        int res = 10, cur = 9;
        for (int i = 0; i < n - 1; ++i) {
            cur *= 9-i;
            res += cur;
        }
        return res;
    }

};

int main() {

    return 0;
}
