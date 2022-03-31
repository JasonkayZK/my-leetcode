#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"

class Solution {
private:

public:

    double average(vector<int> &salary) {
        int min_x = 100001, max_x = 0, n = salary.size();
        double sum = 0.0;

        for (const auto &item: salary) {
            min_x = min(min_x, item);
            max_x = max(max_x, item);
            sum += item;
        }

        return (sum - min_x - max_x) / (n - 2.0);
    }

};

int main() {


    return 0;
}
