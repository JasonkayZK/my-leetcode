#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
public:

    int missingNumber(vector<int> &nums) {
        int n = int(nums.size());
        return (0 + n) * (n + 1) / 2 - accumulate(nums.begin(), nums.end(), 0);
    }

private:


};

int main() {


    return 0;
}
