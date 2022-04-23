#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:

public:

    vector<int> topKFrequent(vector<int> &nums, int k) {
        // count frequent
        unordered_map<int, int> m;
        for (const auto &item: nums) {
            m[item]++;
        }

        // find top-k
        auto cmp = [](const pair<int, int> &x, const pair<int, int> &y) {
            return x.second > y.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (const auto &item: m) {
            if (pq.size() < k) {
                pq.emplace(item);
                continue;
            }

            if (item.second > pq.top().second) {
                pq.pop();
                pq.emplace(item);
            }
        }

        // yield result
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }

};

int main() {

    vector<int> l{4, 1, -1, 2, -1, 2, 3};
    Solution().topKFrequent(l, 2);

    return 0;
}
