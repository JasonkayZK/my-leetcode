#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
public:

    int distributeCandies(vector<int> &candyType) {
        int n = int(candyType.size());
        if (n <= 1) return n;

        unordered_set<int> s(candyType.begin(), candyType.end());
        return min(n / 2, int(s.size()));
    }

private:


};

int main() {


    return 0;
}
