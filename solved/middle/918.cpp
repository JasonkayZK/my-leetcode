#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"

class Solution {
private:

public:

    int maxSubarraySumCircular(vector<int> &nums) {
        int sum = 0, max_sum = nums[0], cur_max = 0, min_sum = nums[0], cur_min = 0;

        for (const auto &item : nums) {
            cur_max = max(cur_max + item, item);
            max_sum = max(cur_max, max_sum);
            cur_min = min(cur_min + item, item);
            min_sum = min(cur_min, min_sum);
            sum += item;
        }

        return max_sum > 0 ? max(max_sum, sum - min_sum) : max_sum;
    }

};

int main() {


    return 0;
}
