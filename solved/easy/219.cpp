#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
private:

public:

    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        int n = int(nums.size());
        if (n <= 1) return false;

        int left = 0;
        unordered_set<int> s;
        while (left < k && left < n) { // build window
            if (s.count(nums[left]) > 0) return true;
            s.emplace(nums[left]);
            left++;
        }

        // slide window
        while (left < n) {
            if (s.count(nums[left]) > 0) return true;
            s.emplace(nums[left]);
            s.erase(nums[left - k]);
            left++;
        }
        return false;
    }

};

int main() {

    vector<int> l = {1, 2, 3, 1, 2, 3};
    Solution().containsNearbyDuplicate(l, 2);

    return 0;
}
