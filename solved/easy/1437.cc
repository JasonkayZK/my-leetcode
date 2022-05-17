#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
public:

    bool kLengthApart(vector<int>& nums, int k) {
        int n = int(nums.size());
        if (n <= 1) return true;
        if (k <= 0) return true;

        int l = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                if (l == -1 || i - l > k) l = i;
                else return false;
            }
        }
        return true;
    }

private:


};

int main() {

    vector<int> l = {1,0,0,0,1,0,0,1};
    std::cout << Solution().kLengthApart(l , 2);

    return 0;
}
