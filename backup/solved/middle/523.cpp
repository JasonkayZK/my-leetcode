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
/* 前缀和 + HashMap + 同余定理 */
public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        int n = nums.size();
        if (n < 2) return false;

        unordered_map<int, int> res_map;
        res_map[0] = -1;
        int reminder = 0;
        for (int i = 0; i < n; ++i) {
            reminder = (reminder + nums[i]) % k;
            if (res_map.count(reminder)) {
                int prevIndex = res_map[reminder];
                if (i - prevIndex >= 2) {
                    return true;
                }
            } else {
                res_map[reminder] = i;
            }
        }
        return false;
    }
};
