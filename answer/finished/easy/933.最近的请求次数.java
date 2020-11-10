import java.util.LinkedList;
import java.util.Queue;

/*
 * @lc app=leetcode.cn id=933 lang=java
 *
 * [933] 最近的请求次数
 */

/* Test Case:

["RecentCounter","ping","ping","ping","ping"]
[[],[1],[100],[3001],[3002]]

*/

/* Method 1: Queue */
class RecentCounter {

    Queue<Integer> q;

    public RecentCounter() {
        q = new LinkedList<>();
    }
    
    public int ping(int t) {
        while(!q.isEmpty() && t - q.peek() > 3000) q.poll();
        q.offer(t);
        return q.size();
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter();
 * int param_1 = obj.ping(t);
 */
// @lc code=end

