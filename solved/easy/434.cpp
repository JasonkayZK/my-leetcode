#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <memory>
#include <cmath>
#include <numeric>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <queue>
#include <random>

using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int res = 0, len = s.size();
        for (int i = 0; i < len; ++i) {
            if ((i == 0 || s[i - 1] == ' ') && s[i] != ' ') {
                res++;
            }
        }
        return res;
    }
};
