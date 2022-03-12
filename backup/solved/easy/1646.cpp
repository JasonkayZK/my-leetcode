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

using namespace std;

class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n == 0) return 0;
        vector<int> list(n + 1);
        list[1] = 1;
        for (int i = 2; i <= n; ++i) {
            list[i] = list[i / 2] + i % 2 * list[i / 2 + 1];
        }
        return *max_element(list.begin(), list.end());
    }
};
