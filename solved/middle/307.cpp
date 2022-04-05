#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class NumArray {
private:
    SegmentTree tree;
    int size;

public:
    explicit NumArray(const vector<int> &nums) {
        size = int(nums.size());
        this->tree = SegmentTree(size * 4);
        this->tree.build(0, 0, size - 1, nums);
    }

    void update(int index, int val) {
        tree.change(index, val, 0, 0, size - 1);
    }

    int sumRange(int left, int right) {
        return tree.range(left, right, 0, 0, size - 1);
    }
};

int main() {

    return 0;
}
