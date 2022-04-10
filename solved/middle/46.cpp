#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:

    void helper(vector<vector<int>> &res, vector<int> &cur, int idx, int n) {
        if (idx == n) {
            res.push_back(cur);
            return;
        }

        for (int i = idx; i < n; ++i) {
            swap(cur[i], cur[idx]); // cur yield
            helper(res, cur, idx+1, n);
            swap(cur[i], cur[idx]); // go backtrace
        }
    }


public:

    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> res;
        helper(res, nums, 0, int(nums.size()));
        return res;
    }

};

int main() {

    return 0;
}
