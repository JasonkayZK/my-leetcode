/*
 * @lc app=leetcode.cn id=1184 lang=java
 *
 * [1184] 公交站间的距离
 */

/* Test Case:

[1,2,3,4]
0
1
[1,2,3,4]
0
2
[1,2,3,4]
0
3


*/

/* Method 1: Brute Force 

    Time: O(n)
    Space: O(1)
*/
class Solution {
    public int distanceBetweenBusStops(int[] distance, int start, int destination) {
        if (destination == start) return 0;
        int rightSum = 0, leftSum = 0;
        if (destination < start) {
            int swap = destination;
            destination = start;
            start = swap;
        }

        for (int i = start; i < destination; ++i) leftSum += distance[i];
        for (int i = destination; i < distance.length; ++i) rightSum += distance[i];
        for (int i = 0; i < start; ++i) rightSum += distance[i];

        return Math.min(rightSum, leftSum);
    }
}

