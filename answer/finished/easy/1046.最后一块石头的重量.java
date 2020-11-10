import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

/*
 * @lc app=leetcode.cn id=1046 lang=java
 *
 * [1046] 最后一块石头的重量
 */

/* Test Case:

[1]
[1,2]
[2,1]
[2,7,4,1,8,1]
[2,3,1]

*/

/* Method 1: Simulation: Max Pile */
class Solution {
    public int lastStoneWeight(int[] stones) {
        Queue<Integer> queue = new PriorityQueue<>(stones.length, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o2 - o1;
            }
        });

        for (int n : stones) queue.offer(n);

        while (queue.size() > 1) {
            int bigger = queue.poll();
            int smaller = queue.poll();
            if (bigger - smaller > 0) queue.offer(bigger - smaller);
        }

        return queue.isEmpty() ? 0 : queue.poll();
    }
}

