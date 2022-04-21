#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:

    void dfs_helper(const vector<int> &nums, vector<vector<int>> &res, vector<int> &cur, int idx, int len, int n) {
        if (cur.size() == len) { // yield result
            res.push_back(cur);
            return;
        }

        if (idx >= n) { // recursive boundary
            return;
        }

        // use cur value
        cur.push_back(nums[idx]);
        dfs_helper(nums, res, cur, idx + 1, len, n);

        // backtrace
        cur.pop_back();
        dfs_helper(nums, res, cur, idx + 1, len, n);
    }

public:

    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> cur;
        res.emplace_back();
        for (int i = 1, n = int(nums.size()); i <= n; ++i) {
            dfs_helper(nums, res, cur, 0, i, n);
        }
        return res;
    }

};

int main() {

    vector<int> l = {0};
    Solution().subsets(l);

    return 0;
}
