#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int> TABLE{
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
};

class Solution {
public:
    int romanToInt(string s) {
        int res = 0, i;
        for (i = 0; i < s.size() - 1; ++i) {
            res += TABLE[s[i + 1]] <= TABLE[s[i]] ? TABLE[s[i]] : (TABLE[s[i + 1]] - TABLE[s[i++]]);
        }
        res += i < s.size() ? TABLE[s[i]] : 0;
        return res;
    }
};

int main() {
    auto sol = Solution();

    cout << sol.romanToInt("III") << endl;
    cout << sol.romanToInt("IV") << endl;
    cout << sol.romanToInt("IX") << endl;
    cout << sol.romanToInt("LVIII") << endl;
    cout << sol.romanToInt("MCMXCIV") << endl;

    return 0;
}