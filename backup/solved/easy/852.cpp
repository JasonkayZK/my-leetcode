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

using namespace std;

class Solution {
public:
/* Method 1: Binary Search */
    int peakIndexInMountainArray(vector<int> &arr) {
        int len = arr.size(), l = 0, r = len - 2, mid;
        while (l < r) {
            mid = l + ((r - l) >> 2);
            if (condition(arr, mid, len)) {
                return mid;
            } else if (arr[mid] <= arr[mid - 1]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    bool condition(vector<int> &arr, int mid, int len) {
        return !(mid <= 0 || mid >= len - 1) && arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1];
    }
};
