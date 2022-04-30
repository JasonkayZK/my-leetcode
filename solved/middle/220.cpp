#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

/* Method 1: Set
class Solution {
private:

public:

    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        int n = int(nums.size());
        if (n <= 1) return false;

        set<int> s;
        for (int i = 0; i < n; ++i) {
            auto iter = s.lower_bound(max(nums[i], INT_MIN + t) - t);
            if (iter != s.end() && *iter <= min(nums[i], INT_MAX - t) + t) {
                return true;
            }
            s.insert(nums[i]);
            if (i >= k) {
                s.erase(nums[i - k]);
            }
        }
        return false;
    }

};
*/

/* Method 2: Array to bucket */
class Solution {
private:

    long long max_bucket_cnt;

    // bucket_cnt=t+1, x=(t+1)*k+b {0<=b<=t}
    int get_bucket_idx(int val) {
        // [-1, -10] to bucket {-1} => (-10 + 1)/10 - 1 = -1
        return val < 0 ? (val + 1ll) / max_bucket_cnt - 1 : val / max_bucket_cnt;
    }

public:

    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        int n = int(nums.size());
        if (n <= 1) return false;

        max_bucket_cnt = t + 1ll;
        unordered_map<long long, int> m;
        for (int i = 0; i < n; ++i) {
            long long x = nums[i];
            long long bucket_idx = get_bucket_idx(x);
            if (m.count(bucket_idx)) { // current bucket
                return true;
            }
            if (m.count(bucket_idx - 1) && abs(x - m[bucket_idx - 1]) <= t) { // prev bucket
                return true;
            }
            if (m.count(bucket_idx + 1) && abs(x - m[bucket_idx + 1]) <= t) { // next bucket
                return true;
            }

            m[bucket_idx] = nums[i];
            if (i >= k) {
                m.erase(get_bucket_idx(nums[i - k]));
            }
        }
        return false;
    }

};


int main() {

    vector<int> l = {2147483647, -1, 2147483647};
    debug(Solution().containsNearbyAlmostDuplicate(l, 1, 2147483647));
    debug((-1 + 1ll) / 2147483647);

    return 0;
}
