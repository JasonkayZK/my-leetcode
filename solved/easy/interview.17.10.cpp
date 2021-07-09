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
    /* Method：Moore Election */
    int majorityElement(vector<int> &nums) {
        int i, cnt = 0, res = nums[0], size = nums.size();
        // Election
        for (i = 0; i < size; ++i) {
            if (res == nums[i]) cnt++;
            else cnt--;
            if (cnt < 0) {
                res = nums[i];
                cnt++;
            }
        }

        // Check
        for (i = cnt = 0; i < size; ++i) {
            if (nums[i] == res) cnt++;
        }
        return cnt > size / 2 ? res : -1;
    }
};
