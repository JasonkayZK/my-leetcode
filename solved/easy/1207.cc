#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
public:

    bool uniqueOccurrences(vector<int> &arr) {
        int n = int(arr.size());
        if (n <= 0) return true;

        int m[4];
        fill(m, m + 4, 0);
        for (const auto &item: arr) {
            ++m[item + 0];
        }

        bitset<4> b;
        for (const auto &item: m) {
            if (item <= 0) continue;
            if (b.test(item)) return false;
            else b.set(item);
        }

        return true;
    }

private:


};

int main() {

    vector<int> l = {1, 2, 2, 1, 1, 3};
    Solution().uniqueOccurrences(l);

    return 0;
}
