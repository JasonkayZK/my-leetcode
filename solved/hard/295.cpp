#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <memory>
#include <cmath>
#include <numeric>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <queue>

using namespace std;

/* 大根堆 + 小根堆（大小顶堆问题） */
class MedianFinder {
private:
    priority_queue<int, vector<int>, less<>> minQueue;
    priority_queue<int, vector<int>, greater<>> maxQueue;

public:
    /** initialize your data structure here. */
    MedianFinder() = default;

    void addNum(int num) {
        if (minQueue.empty() || num <= minQueue.top()) {
            minQueue.push(num);
            if (maxQueue.size() + 1 < minQueue.size()) {
                maxQueue.push(minQueue.top());
                minQueue.pop();
            }
        } else {
            maxQueue.push(num);
            if (maxQueue.size() > minQueue.size()) {
                minQueue.push(maxQueue.top());
                maxQueue.pop();
            }
        }
    }

    double findMedian() {
        if (minQueue.size() > maxQueue.size()) {
            return minQueue.top();
        }
        return (minQueue.top() + maxQueue.top()) / 2.0;
    }
};
