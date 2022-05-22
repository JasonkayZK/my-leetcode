#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
public:

    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = int(capacity.size());
        if (n <= 0) return 0;

        vector<long> v(n);
        for (int i = 0; i < n; ++i) {
            v[i] = capacity[i] - rocks[i];
        }
        sort(v.begin(), v.end());

        int res = 0;
        long cur = additionalRocks;
        for (const auto &item: v) {
            cur -= item;
            if (cur >= 0) ++res;
        }
        return res;
    }

private:


};

int main() {


    return 0;
}
