#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"

class Solution {
private:

public:

};

class MyQueue {
private:
    stack<int> inStk, outStk;

    void in2out() {
        while (!inStk.empty()) {
            outStk.push(inStk.top());
            inStk.pop();
        }
    }

public:
    MyQueue() = default;

    void push(int x) {
        inStk.push(x);
    }

    int pop() {
        if (outStk.empty()) {
            in2out();
        }
        int x = outStk.top();
        outStk.pop();
        return x;
    }

    int peek() {
        if (outStk.empty()) {
            in2out();
        }
        return outStk.top();
    }

    bool empty() {
        return inStk.empty() && outStk.empty();
    }
};


int main() {


    return 0;
}
