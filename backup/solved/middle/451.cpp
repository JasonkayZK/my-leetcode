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

using PIC = pair<int, char>;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> c_map;
        for (auto &c: s) {
            c_map[c]++;
        }

        priority_queue<PIC, vector<PIC>, less<>> pq;
        for (auto &[k, v] : c_map) {
            pq.push({v, k});
        }

        string res;
        while (!pq.empty()) {
            auto[num, c] = pq.top();
            pq.pop();
            res += string(num, c);
        }
        return res;
    }
};
