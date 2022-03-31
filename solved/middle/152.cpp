#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"

class Solution {
private:

public:

    int maxProduct(vector<int> &nums) {
        int n = int(nums.size());
        if (n <= 0) return 0;
        if (n == 1) return nums[0];

        int res = nums[0];
        vector<int> maxDp(n), minDp(n);
        maxDp[0] = nums[0], minDp[0] = nums[0];

        for (int i = 1; i < n; ++i) {
            maxDp[i] = max(maxDp[i - 1] * nums[i], max(nums[i], minDp[i - 1] * nums[i]));
            minDp[i] = min(minDp[i - 1] * nums[i], min(nums[i], maxDp[i - 1] * nums[i]));
            res = max(res, maxDp[i]);
        }

        return res;
    }

};

int main() {


    return 0;
}
