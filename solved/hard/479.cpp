#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:

public:

    int largestPalindrome(int n) {
        if (n == 1) return 9;

        long long left = pow(10, n - 1);
        long long right = pow(10, n) - 1;

        for (long long i = right; i >= left; --i) {
            // build palindrome
            long long palindrome = i, temp = i;
            while (temp > 0) {
                palindrome = palindrome * 10 + temp % 10;
                temp /= 10;
            }

            // check if could devide
            for (long long j = right; j * j >= palindrome; --j) {
                if (palindrome % j == 0) return palindrome % 1337;
            }
        }

        return -1;
    }

};

int main() {

    return 0;
}
