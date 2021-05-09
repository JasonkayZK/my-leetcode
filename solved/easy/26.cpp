//
// Created by jasonkay on 2021/5/9.
//
#include <vector>
#include <iostream>

using namespace std;

/* Solution 1:
class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() < 2) return nums.size();
        int cur = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[cur] != nums[i]) nums[++cur] = nums[i];
        }
        return ++cur;
    }
};
 */

/* Solution 2: STL */
class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        return distance(nums.begin(), unique(nums.begin(), nums.end()));
    }
};

int main() {
    auto vec = vector<int>{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << Solution().removeDuplicates(vec) << endl;
}
