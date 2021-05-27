#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <memory>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int c = x^y;
        int res = 0;
        while (c) {
            res += c & 1;
            c >>= 1;
        }
        return res;
    }
};
