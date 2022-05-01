#include "../../utils/utils.h"
#include "../../data_structure/list.h"
#include "../../data_structure/tree.h"
#include "../../data_structure/trie.h"
#include "../../data_structure/segment_tree.h"
#include "../../data_structure/union_find.h"

class Solution {
private:

public:

    int minimumCardPickup(vector<int> &cards) {
        int res = INT_MAX, n = int(cards.size());
        unordered_map<int,int> m;

        for (int i = 0; i < n; ++i) {
            if (m.count(cards[i]) > 0) {
                res = min(res, i - m[cards[i]] + 1);
                m.erase(cards[m[cards[i]]]);
            }
            m.emplace(make_pair(cards[i], i));
        }
        return res == INT_MAX ? -1 : res;
    }

};

int main() {

    vector<int> l = {95, 11, 8, 65, 5, 86, 30, 27, 30, 73, 15, 91, 30, 7, 37, 26, 55, 76, 60, 43, 36, 85, 47, 96, 6};
    Solution().minimumCardPickup(l);

    return 0;
}
