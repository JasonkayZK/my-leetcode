#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:
    int nextNum(int n) {
        int sum = 0;
        while (n > 0) {
            int cur = n % 10;
            sum += cur * cur;
            n /= 10;
        }
        return sum;
    }

public:

    bool isHappy(int n) {
        unordered_set<int> s;
        while (s.count(n) == 0) {
            if (n == 1) return true;
            s.emplace(n);
            n = nextNum(n);
        }

        return false;
    }

};

int main() {

    return 0;
}
