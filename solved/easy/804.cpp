#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

const static string MORSE[26] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
        "....", "..", ".---", "-.-", ".-..", "--", "-.",
        "---", ".--.", "--.-", ".-.", "...", "-", "..-",
        "...-", ".--", "-..-", "-.--", "--.."
};

class Solution {
private:

public:

    int uniqueMorseRepresentations(vector<string> &words) {
        unordered_set<string> seen;
        for (auto &word: words) {
            string code;
            for (auto &c: word) {
                code.append(MORSE[c - 'a']);
            }
            seen.emplace(code);
        }
        return seen.size();
    }


};

int main() {

    return 0;
}
