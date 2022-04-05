#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"

class Solution {
private:

public:

    int majorityElement(vector<int>& nums) {
        int n = int(nums.size());
        if (n == 0) return 0;

        int cnt = 1, res = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] != res) {
                cnt--;
                if (cnt <= 0) {
                    res = nums[i];
                    cnt=1;
                }
            } else {
                cnt++;
            }
        }

        return res;
    }

};

int main() {

    return 0;
}
