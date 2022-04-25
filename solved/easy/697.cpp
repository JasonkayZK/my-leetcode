#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:

public:

    int findShortestSubArray(vector<int> &nums) {
        int n = int(nums.size());
        if (n <= 1) return n;

        // build map
        // m[item][0] = cnt, m[item][1] = first_idx, m[item][2] = last_idx
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < n; ++i) {
            if (m.count(nums[i]) > 0) {
                m[nums[i]][0]++;
                m[nums[i]][2] = i;
            } else {
                m[nums[i]] = {1, i, i};
            }
        }

        // yield result
        int cnt_max = 0, res = 0;
        for (const auto &[_, vec]: m) {
            if (cnt_max < vec[0]) {
                cnt_max = vec[0];
                res = vec[2] - vec[1] + 1;
            } else if (cnt_max == vec[0]) {
                res = min(res, vec[2] - vec[1] + 1);
            }
        }

        return res;
    }

};

int main() {

    return 0;
}
