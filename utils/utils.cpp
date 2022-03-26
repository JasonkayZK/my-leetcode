//
// Created by JasonkayZK on 2022/3/26.
//

#include "utils.h"

int dirs[9][2] = {{0,  0},
        {1,  0},
        {-1, 0},
        {0,  1},
        {0,  -1},
        {-1, -1},
        {-1, 1},
        {1,  -1},
        {1,  1}};

void print_vec(const vector<int> &arr) {
    std::for_each(arr.begin(), arr.end(), [](const auto &i) { std::cout << i << " "; });
    cout << "\n";
}

void swap(vector<int> &nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

vector <string> split(const string &s, const char delimiter) {
    vector <string> tokens;
    string token;
    istringstream token_stream(s);
    while (getline(token_stream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int rob_helper(const vector<int> &nums, int start, int end) {
    int n = end - start;
    if (n <= 0) return 0;
    if (n == 1) return nums[start];
    if (n == 2) return max(nums[start], nums[end-1]);

    vector<int> dp(n);
    dp[0] = nums[start];
    dp[1] = max(nums[start], nums[start+1]);
    for (int i = 2; i < n; ++i) {
        dp[i] = max(dp[i - 2] + nums[start+i], dp[i - 1]);
    }

    return dp[n - 1];
}
