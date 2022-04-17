#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:
    int max_num = 3;

public:

    int thirdMax(vector<int> &nums) {
        int n = int(nums.size());
        if (n <= 0) return 0;

        auto cmp = [](const int &x, const int &y) -> bool {
            return x < y;
        };
        set<int, decltype(cmp)> pq(cmp);

        for (const auto &item: nums) {
            pq.emplace(item);

            if (pq.size() > max_num) {
                pq.erase(pq.begin());
            }
        }

        int res;
        if (pq.size() < max_num) { // no x-th max, return max
            res = *pq.rbegin();
        } else {
            res = *pq.begin();
        }
        return res;
    }

};

int main() {

    vector<int> l = {1, 2, 2, 5, 3, 5};
    Solution().thirdMax(l);

    return 0;
}
