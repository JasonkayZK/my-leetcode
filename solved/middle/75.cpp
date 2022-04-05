#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
public:
    void sortColors(vector<int> &nums) {
        int n = nums.size();
        if (n <= 1) return;

        int twoCnt = 0, sum = 0;
        for (const auto &item: nums) {
            sum += item;
            twoCnt += item == 2 ? 1 : 0;
        }

        int oneCnt = sum - twoCnt * 2, zeroCnt = n - oneCnt - twoCnt;

        if (zeroCnt > 0) {
            std::fill(nums.begin(), nums.begin() + zeroCnt, 0);
        }
        if (oneCnt > 0) {
            std::fill(nums.begin() + zeroCnt, nums.begin() + zeroCnt + oneCnt, 1);
        }

        std::fill(nums.begin() + oneCnt + zeroCnt, nums.end(), 2);
    }
};

int main() {

    vector<int> l = {2, 0, 1};
    Solution().sortColors(l);

    return 0;
}
