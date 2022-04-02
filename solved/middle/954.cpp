#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"

class Solution {
private:

public:

    bool canReorderDoubled(vector<int> &arr) {
        int n = int(arr.size());
        if (n <= 0) return true;
        if (n == 1) return false;

        unordered_map<int, int> mp;
        for (const auto &item: arr) {
            mp[item]++;
        }

        // special 0
        if (mp[0] % 2 != 0) return false;
        else mp.erase(0);

        // sort
        sort(arr.begin(), arr.end(), [](const int &x, const int &y) {
            return abs(x) < abs(y);
        });

        // remove
        for (const auto &item: arr) {
            if (item == 0) continue;

            if (mp.count(item) > 0 && mp.count(2 * item) > 0) {
                mp[item]--;
                if (mp[item] == 0) mp.erase(item);
                mp[item * 2]--;
                if (mp[item*2] == 0) mp.erase(item*2);
            }
        }

        return mp.empty();
    }

};

int main() {

    vector<int> l = {1,2,1,-8,8,-4,4,-4,2,-2};
    Solution().canReorderDoubled(l);

    return 0;
}
