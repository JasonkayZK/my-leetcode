#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:

public:

    int maximumWealth(vector<vector<int>>& accounts) {
        int res = 0;
        for (const auto &item : accounts){
            res = max(res, accumulate(item.begin(), item.end(), 0));
        }
        return res;
    }

};

int main() {

    return 0;
}
