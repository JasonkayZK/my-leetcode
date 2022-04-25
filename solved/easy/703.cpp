#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class KthLargest {
private:

    struct cmp {
        bool operator()(const int &x, const int &y) {
            return x > y;
        }
    };

    priority_queue<int, vector<int>, cmp> pq;

    int limit;

public:
    KthLargest(int k, vector<int> &nums) {
        limit = k;

        for (const auto &item: nums) {
            if (pq.size() < k) {
                pq.emplace(item);
                continue;
            }
            if (item > pq.top()) {
                pq.pop();
                pq.emplace(item);
            }
        }
    }

    int add(int val) {
        if (pq.size() < limit) {
            pq.emplace(val);
        } else if (val > pq.top()) {
            pq.pop();
            pq.emplace(val);
        }

        if (pq.size() < limit) return 0; // no k-th num
        return pq.top();
    }
};

int main() {

    return 0;
}
