#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

/* Solution 1: Single BFS
class Solution {
private:

    char dict[4] = {'A', 'C', 'G', 'T'};

public:

    int minMutation(string start, string end, vector<string> &bank) {
        int m = int(start.size()), n = int(end.size());
        if (m != n) return -1;

        unordered_set<string> bank_set(bank.begin(), bank.end());
        if (bank_set.count(end) <= 0) return -1;

        queue<string> q;
        unordered_set<string> visited{};
        q.emplace(start);
        visited.emplace(start);
        int res = -1;
        while (!q.empty()) {
            ++res;
            for (int i = 0, size = int(q.size()); i < size; ++i) {
                string cur = q.front();
                q.pop();
                if (cur == end) { return res; }
                else visited.emplace(cur);

                for (int j = 0; j < m; ++j) {
                    string next = cur;
                    for (const auto &item: dict) {
                        next[j] = item;
                        if (visited.count(next) <= 0 && bank_set.count(next) > 0) {
                            q.emplace(next);
                        }
                    }
                }
            }
        }
        return -1;
    }

};
*/

/* Solution 2: Bilateral BFS */
class Solution {
private:

    char dict[4] = {'A', 'C', 'G', 'T'};

public:

    int minMutation(string start, string end, vector<string> &bank) {
        int m = int(start.size()), n = int(end.size());
        if (m != n) return -1;

        unordered_set<string> bank_set(bank.begin(), bank.end());
        if (bank_set.count(end) <= 0) return -1;

        queue <string> q1, q2;
        q1.emplace(start);
        q2.emplace(end);
        unordered_map<string, int> visited1, visited2;
        visited1.emplace(make_pair(start, 0));
        visited2.emplace(make_pair(end, 0));

        while (!q1.empty() && !q2.empty()) {
            int res = -1;
            if (q1.size() <= q2.size()) res = update(q1, bank_set, visited1, visited2);
            else res = update(q2, bank_set, visited2, visited1);
            if (res != -1) return res;
        }
        return -1;
    }

    int update(queue <string> &cur_q, const unordered_set<string> &bank_set,
               unordered_map<string, int> &cur, unordered_map<string, int> &other) {

        for (int i = 0, size = int(cur_q.size()); i < size; ++i) {
            string cur_str = cur_q.front();
            cur_q.pop();
            int cur_res = cur[cur_str];

            for (int j = 0; j < 8; ++j) {
                string next = cur_str;
                for (const auto &item: dict) {
                    if (item == cur_str[j]) continue;

                    next[j] = item;
                    if (cur.count(next) > 0 || bank_set.count(next) <= 0) continue;
                    if (other.count(next) > 0) return other[next] + cur_res + 1;
                    cur_q.emplace(next);
                    cur.emplace(make_pair(next, cur_res + 1));
                }
            }
        }

        return -1;
    }

};

int main() {

    vector<string> l = {"AATTCCGG","AACCTGGG","AACCCCGG","AACCTACC"};
    std::cout << Solution().minMutation("AACCTTGG", "AATTCCGG", l);

    return 0;
}
