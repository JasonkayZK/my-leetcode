#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:

public:

    string largestNumber(vector<int> &nums) {

        sort(nums.begin(), nums.end(), [](const int &x, const int &y) -> bool {
            string numA = to_string(x);
            string numB = to_string(y);
            int lenA = numA.size();
            int lenB = numB.size();
            for (int i = 0; i < lenA + lenB; i++) {
                char charA = i < lenA ? numA[i] : numB[i - lenA];
                char charB = i < lenB ? numB[i] : numA[i - lenB];
                if (charA != charB) {
                    return (charA > charB);
                }
            }
            return false;
        });

        if (nums[0] == 0) {
            return "0";
        }

        string ret;
        for (int &x: nums) {
            ret += to_string(x);
        }
        return ret;
    }

};

int main() {

    vector<int> l = {3, 30, 34, 5, 9};
    cout << Solution().largestNumber(l);

    return 0;
}
