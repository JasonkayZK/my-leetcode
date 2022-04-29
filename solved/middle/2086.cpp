#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:

public:

    int minimumBuckets(string street) {
        int n = int(street.size()), res = 0, bucket_pos = -2;

        for (int i = 0; i < n; ++i) {
            if (street[i] == 'H') {
                if (bucket_pos == i - 1) { // has left bucket
                } else if (i + 1 < n && street[i + 1] == '.') { // put bucket to right
                    ++res;
                    bucket_pos = i + 1;
                } else if (i - 1 >= 0 && street[i - 1] == '.') { // put bucket to left
                    res++;
                } else { // no answer
                    return -1;
                }
            }
        }
        return res;
    }

};

int main() {

    cout << Solution().minimumBuckets("H");

    return 0;
}
