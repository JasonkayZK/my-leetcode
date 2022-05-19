#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
public:

    int minMoves2(vector<int> &nums) {
        int n = int(nums.size());
        if (n <= 1) return 0;

        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        int res = 0, mid = nums[n / 2];
        for (int i = 0; i < n; ++i) {
            res += abs(nums[i] - mid);
        }
        return res;
    }

private:


};

int main() {


    return 0;
}
