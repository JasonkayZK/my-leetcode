#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:

public:

    int countKDifference(vector<int> &nums, int k) {
        int n = int(nums.size());
        if (n <= 1) return 0;

        map<int, int> m;
        for (const auto &item: nums) {
            m[item]++;
        }

        int res = 0;
        for (const auto &item: m) {
            if (m.count(item.first + k) > 0) res += item.second * m[item.first + k];
        }

        return res;
    }

};

int main() {

    return 0;
}
