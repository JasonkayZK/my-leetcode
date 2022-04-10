#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:

public:

    bool wordPattern(string pattern, string s) {
        auto arr = split(s, ' ');

        int m = pattern.size(), n = arr.size();
        if (m != n) return false;

        unordered_map<string, char> wordToPatternMap;
        unordered_map<char, string> patternToWordMap;
        for (int i = 0; i < n; ++i) {
            if (wordToPatternMap.count(arr[i]) <= 0 && patternToWordMap.count(pattern[i]) <= 0) {
                wordToPatternMap.emplace(pair{arr[i], pattern[i]});
                patternToWordMap.emplace(pair{pattern[i], arr[i]});
                continue;
            } else {
                if (wordToPatternMap[arr[i]] != pattern[i]) return false;
            }
        }

        return true;
    }

};

int main() {

    Solution().wordPattern("abba", "dog cat cat fish");

    return 0;
}
