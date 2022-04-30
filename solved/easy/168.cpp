#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
private:

public:

    string convertToTitle(int columnNumber) {
        string res;
        while (columnNumber > 0) {
            --columnNumber;
            int residue = columnNumber % 26;
            res.push_back('A' + residue);
            columnNumber /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }

};

int main() {
    debug(char(char(25-1) + 'A'));

    return 0;
}
