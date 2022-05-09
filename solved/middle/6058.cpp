#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
public:

    int countTexts(string pressedKeys) {
        int n = int(pressedKeys.size());
        if (n <= 1) return n;

        long long three_map[100000 + 1];
        three_map[0] = 1;
        three_map[1] = 1;
        three_map[2] = 2;
        three_map[3] = 4;
        for (int i = 4; i <= 100000; ++i) {
            three_map[i] = (three_map[i - 1] + three_map[i - 2] + three_map[i - 3]) % RES_NUM;
        }

        long long four_map[100000 + 1];
        four_map[0] = 1;
        four_map[1] = 1;
        four_map[2] = 2;
        four_map[3] = 4;
        four_map[4] = 8;
        for (int i = 5; i <= 100000; ++i) {
            four_map[i] = (four_map[i - 1] + four_map[i - 2] + four_map[i - 3] + four_map[i - 4]) % RES_NUM;
        }

        long long res = 1;
        int i = 0;
        while (i < n) {
            char cur_char = pressedKeys[i];
            int cur_cnt = 0;
            while (i < n && pressedKeys[i] == cur_char) {
                cur_cnt++;
                i++;
            }

            long long cur_res;
            if (cur_char == '7' || cur_char == '9') {
                cur_res = four_map[cur_cnt];
            } else {
                cur_res = three_map[cur_cnt];
            }
            res = (res * cur_res) % RES_NUM;
        }
        return int(res);
    }

private:

    static constexpr int RES_NUM = 1000000007;
};
