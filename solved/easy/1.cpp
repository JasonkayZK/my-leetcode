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
private:

public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> map{};

        for (int i = 0; i < nums.size(); ++i) {
            if (map.count(target - nums[i]) > 0) {
                return vector{map[target - nums[i]], i};
            } else {
                map.emplace(nums[i], i);
            }
        }

        return {};
    }
};
