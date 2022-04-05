#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:

public:

    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        int n = int(intervals.size());
        if (n <= 1) return intervals;

        std::sort(intervals.begin(), intervals.end(),
                  [](const vector<int> &a, const vector<int> &b) {
                      if (a[0] == b[0]) return a[1]<b[1];
                      else return a[0] < b[0];
                  });

        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (int i = 1; i < n; ++i) {
            int l = intervals[i][0], r = intervals[i][1];

            if (res.back()[1] < l) {
                res.push_back({l, r});
            } else {
                res.back()[1] = max(res.back()[1], r);
            }
        }

        return res;
    }

};

int main() {

    vector<vector<int>> l = {{1,  3},
                             {15, 18},
                             {1,  4},
                             {2,  6},
                             {8,  10},
    };
    Solution().merge(l);

    return 0;
}
