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

using namespace std;

class Solution {
/* 前缀和 + HashMap */
public:
    int findMaxLength(vector<int> &nums) {
        unordered_map<int, int> mp;
        int res = 0, counter = 0;
        mp[0] = -1;

        for (int i = 0, n = nums.size(); i < n; ++i) {
            nums[i] ? counter++ : counter--;
            mp.count(counter) ? res = max(res, i - mp[counter]) : mp[counter] = i;
        }
        return res;
    }
};
