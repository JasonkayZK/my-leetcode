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

using namespace std;

using pii = std::pair<int, int>;
using ll = long long;
using pic = std::pair<int, char>;

void print_vec(const std::vector<int> &arr);

void swap(std::vector<int> &nums, int i, int j);

std::vector <std::string> split(const std::string &s, char delimiter);

int rob_helper(const std::vector<int> &nums, int start, int end);


#endif //MY_LEETCODE_UTILS_H
