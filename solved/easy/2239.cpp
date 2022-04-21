#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:

public:

    int findClosestNumber(vector<int>& nums) {
        int res = INT_MAX;

        for (const auto &item: nums) {
            if (abs(item) < abs(res)) res = item;
            else if (abs(item) == abs(res)) res = max(res, item);
        }
        return res;
    }

};

int main() {

    return 0;
}
