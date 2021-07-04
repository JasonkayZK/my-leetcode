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
    void swap(vector<int> &nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
public:
    vector<int> findErrorNums(vector<int> &nums) {
        int n = nums.size(), i = 0;
        for (i = 0; i < n; ++i) {
            while (nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]) {
                swap(nums, i, nums[i] - 1);
            }
        }

        print_vec(nums);

        int rep, los = 0;
        for (i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                rep = nums[i];
                los = i == 0 ? 1 : nums[i - 1] + 1;
            }
        }
        return vector<int>{rep, los};
    }
};
