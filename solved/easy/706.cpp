#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

/* Method 1: Array
class MyHashMap {
private:
    const int max_bound = 1000000;
    const int min_bound = 0;

    vector<int> m;

    [[nodiscard]] bool checkBound(int key) const {
        return key <= max_bound && key >= min_bound;
    }

public:
    MyHashMap() : m(vector(max_bound + 1, min_bound - 1)) {}

    void put(int key, int value) {
        if (!checkBound(key)) return;

        this->m[key] = value;
    }

    int get(int key) {
        if (!checkBound(key)) return -1;

        return this->m[key];
    }

    void remove(int key) {
        this->m[key] = min_bound-1;
    }
};
*/

/* Method 2: Zipper */
class MyHashMap {
private:
    static const int base = 769;

    vector<list<pair<int, int>>> m;

    static int hash(int key) {
        return key % base;
    }

public:
    MyHashMap() : m(base) {}

    void put(int key, int value) {
        int h = hash(key);

        auto it = std::find_if(m[h].begin(), m[h].end(),
                               [&key](auto e) { return e.first == key; });
        if (it != m[h].end()) { // found
            it->second = value;
        } else { // not found
            m[h].push_back(make_pair(key, value));
        }
    }

    int get(int key) {
        int h = hash(key);

        auto it = std::find_if(m[h].begin(), m[h].end(),
                               [&key](auto e) { return e.first == key; });
        if (it != m[h].end()) { // found
            return it->second;
        } else { // not found
            return -1;
        }
    }

    void remove(int key) {
        int h = hash(key);

        auto it = std::find_if(m[h].begin(), m[h].end(),
                               [&key](auto e) { return e.first == key; });
        if (it != m[h].end()) { // found
            it->second = -1;
        }
    }
};

int main() {

    return 0;
}
