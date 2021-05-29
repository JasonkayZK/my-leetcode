#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <memory>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && !(n & (n - 1));
    }
};
