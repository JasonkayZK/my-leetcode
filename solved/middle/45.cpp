#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"

class Solution {
private:

public:

    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int r = 0, cur = 0, res = 0;
        for (int i = 0; i < n-1; ++i) {
            r = max(r, i + nums[i]);
            if (cur == i) {
                cur = r;
                res++;
            }
        }

        return res;
    }

};

int main() {


    return 0;
}
