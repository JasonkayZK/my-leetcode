#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:

public:

    int scheduleCourse(vector<vector<int>> &courses) {
        sort(courses.begin(), courses.end(), [](const auto &x, const auto &y) {
            return x[1] < y[1];
        });

        priority_queue<int> pq;
        int cur_time = 0;
        for (const auto &item : courses) {
            int span = item[0], deadline = item[1];

            if (cur_time + span <= deadline) {
                cur_time += span;
                pq.emplace(span);
            } else if (!pq.empty() && pq.top() > span) {
                cur_time -= pq.top() - span;
                pq.pop();
                pq.emplace(span);
            }
        }

        return int(pq.size());
    }

};

int main() {

    vector<vector<int>> l = {{5,5}, {4,6}, {2,6}};
    Solution().scheduleCourse(l);

    return 0;
}
