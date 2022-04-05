#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:

public:

    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
        int n = int(candies.size());
        if (n <= 0) return {};
        if (n == 1) return {true};

        int max_num = *max_element(candies.begin(), candies.end());
        vector<bool> res(n);
        for (int i = 0; i < n; ++i) {
            res[i] = candies[i] + extraCandies >= max_num;
        }
        return res;
    }

};

int main() {

    return 0;
}
