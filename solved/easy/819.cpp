#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:

public:

    string mostCommonWord(string paragraph, vector<string> &banned) {
        int m = paragraph.size(), n = banned.size();
        if (m <= 0) return "";

        // build banned map
        unordered_map<string, bool> banned_map(n);
        for (const auto &item: banned) {
            banned_map.emplace(item, true);
        }

        // build cnt map
        unordered_map<string, int> cnt_map;
        string cur;
        for (auto &item: paragraph) {
            if (item == ' ' || item == '!' || item == '?'
                || item == '\'' || item == ',' || item == ';' || item == '.') { // end of a word

                if (!cur.empty() && !banned_map[cur]) { // valid word
                    if (cnt_map.count(cur) > 0) {
                        cnt_map[cur] = cnt_map[cur] + 1;
                    } else {
                        cnt_map.emplace(make_pair(cur, 1));
                    }
                }
                cur.clear();
            } else {
                cur.push_back(tolower(item));
            }
        }

        // last valid word
        if (!cur.empty() && !banned_map[cur]) {
            if (cnt_map.count(cur) > 0) {
                cnt_map[cur] = cnt_map[cur] + 1;
            } else {
                cnt_map.emplace(make_pair(cur, 1));
            }
        }

        // find result
        int cnt = 0;
        string res;
        for (const auto &item: cnt_map) {
            if (item.second > cnt) {
                cnt = item.second;
                res = item.first;
            }
        }

        return res;
    }

};

int main() {

    vector<string> l = {"hit"};
    Solution().mostCommonWord("Bob hit a ball, the hit BALL flew far after it was hit.", l);

    return 0;
}
