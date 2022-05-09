#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
public:

    vector<int> diStringMatch(string s) {
        int n = int(s.size());
        if (n <= 0) return {};

        int left = 0, right = n;
        vector<int> v;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'I') {
                v.push_back(left++);
            } else {
                v.push_back(right--);
            }
        }
        v.push_back(left);

        return v;
    }

private:



};

int main() {


    return 0;
}
