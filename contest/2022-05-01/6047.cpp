#include "../../utils/utils.h"
#include "../../data_structure/list.h"
#include "../../data_structure/tree.h"
#include "../../data_structure/trie.h"
#include "../../data_structure/segment_tree.h"
#include "../../data_structure/union_find.h"

class Solution {
private:

public:

    string removeDigit(string number, char digit) {
        int n = int(number.size());
        string res = "";

        for (int i = 0; i < n; ++i) {
            if (number[i] == digit) {
                string cur = number;
                cur.erase(i, 1);
                if (res == "") {
                    res = cur;
                } else {
                    res = max(cur, res);
                }
            }
        }
        return res;
    }
};

int main() {


    return 0;
}
