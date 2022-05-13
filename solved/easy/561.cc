#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
public:

    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i = 0, size = int(nums.size()); i < size; i += 2) {
            res += nums[i];
        }
        return res;
    }

private:


};

int main() {


    return 0;
}
