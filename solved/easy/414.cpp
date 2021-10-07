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
#include <set>
#include <random>

using namespace std;

class Solution {
public:
    const int TOP = 3;

    int thirdMax(vector<int> &nums) {
        set<int> s;
        for (int & num : nums) {
            s.emplace(num);
            if (s.size() > 3) {
                s.erase(s.begin());
            }
        }
        if (s.size() == 3)
            return *s.begin();
        return *s.rbegin();
    }
};
