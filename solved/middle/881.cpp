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
    int numRescueBoats(vector<int> &people, int limit) {
        int res = 0;
        sort(people.begin(), people.end());
        int l = 0, r = people.size() - 1;
        while (l <= r) {
            if (people[l] + people[r] > limit) {
                --r;
            } else {
                l++, r--;
            }
            ++res;
        }
        return res;
    }
};
