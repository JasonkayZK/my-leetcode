#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"

class Solution {
private:

public:

    vector<int> getRow(int rowIndex) {
        if (rowIndex < 0) return {};
        if (rowIndex == 0) return {1};
        if (rowIndex == 1) return {1,1};

        vector<int> res = {1, 1};
        for (int i = 2; i <= rowIndex; ++i) {
            vector<int> temp(i+1);
            temp[0] = 1;
            temp[i] = 1;

            for (int j = 1; j < i; ++j) {
                temp[j] = res[j-1] + res[j];
            }

            res = temp;
        }

        return res;
    }

};

int main() {

    return 0;
}
