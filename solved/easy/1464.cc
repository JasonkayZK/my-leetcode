#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
public:

    int maxProduct(vector<int>& nums) {
        int n1 = 0;
        int n2 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > n1) {
                n2 = n1;
                n1 = nums[i];
            } else if (nums[i] > n2) {
                n2 = nums[i];
            }
        }

        return (n1 - 1) * (n2 - 1);
    }

private:


};

int main() {


    return 0;
}
