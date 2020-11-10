/*
 * @lc app=leetcode.cn id=961 lang=java
 *
 * [961] 重复 N 次的元素
 */

/* Test Case:

[1,2,3,3]
[2,1,2,5,3,2]
[5,1,5,2,5,3,5,4]
[1,6,6,9]

*/

/* Method 1: HashMap: Counter

    Time: O(n)
    Space: O(n)

class Solution {
    public int repeatedNTimes(int[] A) {
        Map<Integer, Integer> count = new HashMap();
        for (int x: A) {
            count.put(x, count.getOrDefault(x, 0) + 1);
        }

        for (int k: count.keySet())
            if (count.get(k) > 1)
                return k;

        throw new RuntimeException("No valid Answer!");
    }
}
*/

/* Method 2: Compare 

    Time: O(n)
    Space: O(1)
*/
class Solution {
    public int repeatedNTimes(int[] A) {
        for (int step = 1; step <= 3; ++step) {
            for (int i = 0; i < A.length - step; ++i) {
                if (A[i] == A[i + step]) return A[i];
            }
        }

        throw new RuntimeException("No valid Answer!");
    }
}
