#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
public:

    int minDeletionSize(vector <string> &strs) {
        int n = int(strs.size());
        if (n <= 1) return 0;

        int str_len = int(strs[0].size());
        if (str_len <= 1) return 0;

        int cur = 0, res = 0;
        while (cur < str_len) {
            for (int i = 1; i < n; ++i) {
                if (strs[i][cur] - strs[i - 1][cur] < 0) {
                    ++res;
                    break;
                }
            }
            ++cur;
        }
        return res;
    }

private:


};

int main() {


    return 0;
}
