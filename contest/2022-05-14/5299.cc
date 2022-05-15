#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
public:

    int divisorSubstrings(int num, int k) {
        string s = to_string(num);

        if (k > s.size()) {
            return 0;
        }

        int ans = 0;
        for (int i = 0; i < s.size() - k + 1; ++i) {
            if (isDivisor(s, num, i, i + k - 1)) {
                ans++;
            }
        }
        return ans;
    }

private:

    bool isDivisor(const string &str, int num, int l, int r) {
        int cur = 0;
        for (int i = l; i <= r; ++i) {
            cur = cur * 10 + str[i] - '0';
        }
        return cur != 0 && num % cur == 0;
    }

};

int main() {

    Solution().divisorSubstrings(240, 2);

    return 0;
}
