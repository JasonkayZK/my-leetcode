#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:

public:

    vector<int> sortArrayByParity(vector<int> &nums) {
        int n = int(nums.size());
        if (n <= 1) return {nums};

        vector<int> res(n);
        int left = 0, right = n - 1;
        for (int i = 0; i < n; ++i) {
            if ((nums[i] & 0b1) == 0) res[left++] = nums[i];
            else res[right--] = nums[i];
        }
        return res;
    }

};

int main() {
    int a = 666;
    vector<int> b({1, 2, 3});
    string c = "hello world";

    // after
    debug(a, b, c);  // a=666, b=[ 1, 2, 3, ], c=hello world

    return 0;
}
