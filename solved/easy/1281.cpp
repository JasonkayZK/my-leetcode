#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"

class Solution {
private:

public:

    int subtractProductAndSum(int n) {
        long long sum = 0, product = 1;

        while (n != 0) {
            int cur = n % 10;
            sum += cur;
            product *= cur;
            n /= 10;
        }

        return int(product-sum);
    }

};

int main() {


    return 0;
}
