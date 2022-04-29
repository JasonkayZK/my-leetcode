//
// Created by JasonkayZK on 2022/3/26.
//

#ifndef MY_LEETCODE_UTILS_H
#define MY_LEETCODE_UTILS_H

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
#include <sstream>
#include <list>
#include <set>
#include <functional>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <ctime>
#include <type_traits>

using namespace std;

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &V) {
    os << "[ ";
    for (const auto &vv: V) os << vv << ", ";
    os << "]";
    return os;
}

#define debug(...) _debug(#__VA_ARGS__, __VA_ARGS__)

template<typename T>
inline void _debug(const char *format, T t) {
    cerr << format << '=' << t << endl;
}

template<class First, class... Rest>
inline void _debug(const char *format, First first, Rest... rest) {
    while (*format != ',') cerr << *format++;
    cerr << '=' << first << ",";
    _debug(format + 1, rest...);
}

using pii = std::pair<int, int>;
using ll = long long;
using pic = std::pair<int, char>;

bool is_valid_pos(int x, int y, int m, int n);

std::vector<std::string> split(const std::string &s, char delimiter);

template<typename addable>
addable rob_helper(const std::vector<addable> &nums, int start, int end) {
    int n = end - start;
    if (n <= 0) return 0;
    if (n == 1) return nums[start];
    if (n == 2) return max(nums[start], nums[end - 1]);

    vector<addable> dp(n);
    dp[0] = nums[start];
    dp[1] = max(nums[start], nums[start + 1]);
    for (int i = 2; i < n; ++i) {
        dp[i] = max(dp[i - 2] + nums[start + i], dp[i - 1]);
    }

    return dp[n - 1];
}

template<typename comparable>
comparable max_sub_array(const vector<comparable> &a, int start, int end) {
    int n = int(end - start);
    if (n <= 0) return 0;

    vector<comparable> dp(n, 0);
    dp[0] = a[0];

    int res = dp[start];
    for (int i = 1; i < n; ++i) {
        dp[i] = max(dp[i - 1] + a[i + start], a[i + start]);
        res = max(res, dp[i]);
    }

    return res;
}

#endif //MY_LEETCODE_UTILS_H
