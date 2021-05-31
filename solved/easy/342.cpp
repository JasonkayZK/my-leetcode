#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <memory>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        return (n > 0) && !((n & (n-1))) && !(n & 0XAAAAAAAA);
    }
};
