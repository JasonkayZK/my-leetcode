#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
private:

public:

    bool isIsomorphic(string s, string t) {
        int m = s.size(), n = t.size();
        if (m != n) return false;

        unordered_map<char, char> s_to_t;
        unordered_map<char, char> t_to_s;
        for (int i = 0; i < m; ++i) {
            if (s_to_t.count(s[i]) > 0 && s_to_t[s[i]] != t[i]) return false;
            if (t_to_s.count(t[i]) > 0 && t_to_s[t[i]] != s[i]) return false;
            s_to_t[s[i]] = t[i];
            t_to_s[t[i]] = s[i];
        }
        return true;
    }

};

int main() {

    return 0;
}
