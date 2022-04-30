#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
private:

public:

    int titleToNumber(string columnTitle) {
        long long res = 0;
        for (const auto &item: columnTitle) {
            res = res * 26 + item - 'A' + 1;
        }
        return res;
    }

};

int main() {
    "FXSHRXW"

    return 0;
}
