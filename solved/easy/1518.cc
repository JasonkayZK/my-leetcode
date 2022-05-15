#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
public:

    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;

        while (true) {
            int div = numBottles / numExchange;
            if (div <= 0) break;

            res += div;
            numBottles = numBottles % numExchange + div;
        }

        return res;
    }

private:


};

int main() {


    return 0;
}
