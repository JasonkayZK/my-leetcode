#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:

public:

    int missingNumber(vector<int> &nums) {
        int n = int(nums.size());
        if (n <= 0) return 0;

        long long sum = n * (n + 1) / 2;

        return sum - accumulate(nums.begin(), nums.end(), 0);
    }

};

int main() {

    return 0;
}
