#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
public:

    int largestCombination(vector<int>& candidates) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int cur = 0;
            for (const auto &item: candidates) {
                if (((item >> i) & 1) == 1) {
                    cur++;
                }
            }
            res = max(res, cur);
        }
        return res;
    }

private:


};

int main() {


    return 0;
}
