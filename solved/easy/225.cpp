#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class MyStack {
public:
    queue<int> queue1;
    queue<int> queue2;

    /** Initialize your data structure here. */
    MyStack() = default;

    /** Push element x onto stack. */
    void push(int x) {
        queue2.push(x);
        while (!queue1.empty()) {
            queue2.push(queue1.front());
            queue1.pop();
        }
        swap(queue1, queue2);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int r = queue1.front();
        queue1.pop();
        return r;
    }

    /** Get the top element. */
    int top() {
        int r = queue1.front();
        return r;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return queue1.empty();
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
