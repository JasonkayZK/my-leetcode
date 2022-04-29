#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:

public:

    int minCount(vector<int>& coins) {
        int res = 0;
        for (const auto &item: coins) {
            if ((item & 0b1) == 0) res += item >> 1;
            else res += (item >> 1) + 1;
        }
        return res;
    }

};

int main() {

    return 0;
}
