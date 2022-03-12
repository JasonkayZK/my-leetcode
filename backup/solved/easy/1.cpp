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
/* Hashmap */
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0, len = nums.size(); i < len; ++i) {
            if (map.count(target - nums[i])) {
                return {map[target - nums[i]], i};
            } else {
                map[nums[i]] = i;
            }
        }
        return {};
    }
};
