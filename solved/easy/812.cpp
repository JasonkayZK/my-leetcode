#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:

public:

    double largestTriangleArea(vector<vector<int>> &points) {
        double mmax = 0;
        for (int i = 0; i < points.size(); i++)
            for (int j = i + 1; j < points.size(); j++)
                for (int k = j + 1; k < points.size(); k++)
                    mmax = max(mmax, 0.5 * abs(points[i][0] * points[j][1] + points[i][1] * points[k][0] +
                                               points[j][0] * points[k][1] - points[i][0] * points[k][1] -
                                               points[i][1] * points[j][0] - points[j][1] * points[k][0]));
        return mmax;
    }

};

int main() {
    int a = 666;
    vector<int> b({1, 2, 3});
    string c = "hello world";

    // after
    debug(a, b, c);  // a=666, b=[ 1, 2, 3, ], c=hello world

    return 0;
}
