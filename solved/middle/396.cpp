#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:

public:

    // f(0) = F(0)
    // f(x) = F(x-1)+sum - n*(arr[n-x]) x: 1~n-1
    int maxRotateFunction(vector<int> &nums) {
        int n = int(nums.size());
        if (n <= 0) return 0;

        // calculate f(0) & sum
        int f0 = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            f0 += i * nums[i];
        }

        // calculate f(i) and max
        int res = f0;
        for (int i = 1; i < n; ++i) {
            f0 = f0 + sum - n * (nums[n - i]);
            res = max(f0, res);
        }
        return res;
    }

};

int main() {

    vector<int> l{4, 3, 2, 6};
    Solution().maxRotateFunction(l);

    return 0;
}
