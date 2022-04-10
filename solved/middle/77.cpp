#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:

    void helper(vector<vector<int>> &res, vector<int> &curArr, int cur, int n, int k) {
        if (curArr.size() == k) { // long enough to yield result
            res.push_back(curArr);
            return;
        }
        if (cur > n) return; // end of recursion

        curArr.push_back(cur); // pick cur
        helper(res, curArr, cur + 1, n, k);

        // for backtrace
        curArr.pop_back(); // not pick cur
        helper(res, curArr, cur + 1, n, k);
    }

public:

    vector<vector<int>> combine(int n, int k) {
        if (n <= 0 || k <= 0) return {};

        vector<vector<int>> res{};
        vector<int> cur{};
        helper(res, cur, 1, n, k);

        return res;
    }

};

int main() {

    return 0;
}
