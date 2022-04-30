#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
private:

public:

    int smallestRangeI(vector<int> &nums, int k) {
        if (nums.size() < 0) return 0;

        int x_min = nums[0], x_max = nums[0];
        for (const auto &item: nums) {
            x_min = min(x_min, item);
            x_max = max(x_max, item);
        }

        int res = x_max - x_min - 2 * k;
        return res <= 0 ? 0 : res;
    }

};

int main() {
    int a = 666;
    vector<int> b({1, 2, 3});
    string c = "hello world";

    // after
    debug(a, b, c);  // a=666, b=[ 1, 2, 3, ], c=hello world

    return 0;
}
