#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
public:

    int sumOfUnique(vector<int> &nums) {
        int m[101];
        fill(m, m + 101, 0);
        for (const auto &item: nums) {
            ++m[item];
        }

        int res = 0;
        for (int i = 1; i < 101; ++i) {
            if (m[i] == 1) res += i;
        }
        return res;
    }

private:


};

int main() {


    return 0;
}
