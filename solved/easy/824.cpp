#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:

    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

public:

    string toGoatLatin(string sentence) {
        int n = int(sentence.size());
        if (n <= 0) return "";

        string res;
        int idx = 1, i = 0;

        while (i < n) {
            int cur = i;
            while (cur < n && sentence[cur] != ' ') {
                ++cur;
            }

            ++idx;
            if (idx != 2) {
                res.push_back(' ');
            }
            if (vowels.count(sentence[i])) {
                res += sentence.substr(i, cur - i) + 'm' + string(idx, 'a');
            } else {
                res += sentence.substr(i + 1, cur - i - 1) + sentence[i] + 'm' + string(idx, 'a');
            }
            i = cur + 1;
        }

        return res;
    }

};

int main() {

    return 0;
}
