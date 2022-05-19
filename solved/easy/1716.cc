#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
public:

    int totalMoney(int n) {
        int numsOfWeek = n / 7;
        int remainDay = n % 7;
        return (numsOfWeek * (7 * numsOfWeek + 49) + remainDay * (remainDay + 1)) / 2 + remainDay * numsOfWeek;
    }

private:


};

int main() {


    return 0;
}
