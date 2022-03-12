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
    int tribonacci(int n) {
        if (n <= 0) return 0;
        if (n <= 2) return 1;
        int t0 = 0, t1 = 1, t2 = 1, temp = 0;
        for (int i = 3; i <= n; ++i) {
            temp = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = temp;
        }
        return t2;
    }
};
