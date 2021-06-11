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
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> res;
        backtrack(res, nums, 0, nums.size());
        return res;
    }

    void backtrack(vector<vector<int>> &res, vector<int> &cur, int index, int len) {
        if (index >= len) {
            res.emplace_back(cur);
            return;
        }
        for (int i = index; i < len; ++i) {
            swap(cur[i], cur[index]);
            backtrack(res, cur, index+1, len);
            swap(cur[i], cur[index]);
        }
    }
};
