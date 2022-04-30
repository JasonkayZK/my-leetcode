#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
private:

public:



};

int main() {
    int a = 2;
    string s = "123";
    vector<int> v{1, 2, 3};
    unordered_map<string, int> m{{"a", 1},
                                 {"b", 2}};
    unordered_set<string> se{"a", "b"};

    fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold,
               "a: {}, s: {}, v: {}, m: {}, se: {}\n", a, s, v, m, se);

    return 0;
}
