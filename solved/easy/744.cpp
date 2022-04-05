#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"

class Solution {
private:

public:

    char nextGreatestLetter(vector<char> &letters, char target) {
        int n = letters.size();
        if (n <= 0) return target;
        if (n == 1) return letters[0];

        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (r - l) / 2 + l;
            if (letters[mid] > target) r=mid;
            else l = mid+1;
        }

        return letters[r] > target ? letters[r] : letters[0];
    }

};

int main() {

    return 0;
}
