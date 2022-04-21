#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:

public:

    int lengthLongestPath(string input) {
        int n = int(input.size());

        vector<int> level_cnt(n+1);
        int res = 0, cur = 0;

        while (cur < n) {
            int level = 1;

            // count cur depth
            while (cur < n && input[cur] == '\t') {
                level++;
                cur++;
            }

            // count cur length
            int len = 0;
            bool isFile = false;
            while (cur < n && input[cur] != '\n') {
                if (input[cur] == '.') {
                    isFile = true;
                }
                len++;
                cur++;
            }

            // skip \n
            cur++;

            if (level > 1) {
                len += level_cnt[level - 1] + 1;
            }
            if (isFile) {
                res = max(res, len);
            } else {
                level_cnt[level] = len;
            }
        }

        return res;
    }

};

int main() {

    return 0;
}
