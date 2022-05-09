#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
public:

    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        int n = int(nums.size());
        if (n <= 0) return 0;

        int cur_mul = 1, res = 0;
        int l = 0, r = 0;
        while (r < n) {
            cur_mul *= nums[r];
            while (l <= r && cur_mul >= k) {
                cur_mul /= nums[l];
                ++l;
            }
            res += r - l + 1;
            ++r;
        }
        return res;
    }

private:

};

int main() {


    return 0;
}
