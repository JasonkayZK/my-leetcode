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
    int fib(int n) {
        if (n == 0 || n == 1) return n;
        int f0 = 0, f1 = 1;
        for (int i = 1; i < n; ++i) {
            f1 = f0 + f1;
            f0 = f1 - f0;
            f1 %= 1000000007;
        }
        return f1;
    }
};
