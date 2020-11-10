import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=455 lang=java
 *
 * [455] 分发饼干
 */

/* Test Case:

[1,2,3]
[1,1]
[1,2]
[1,2,3]
[10,9,8,7]
[5,6,7,8]


*/


/* Method 1: Greedy 

    Time: O(mlog(m) + nlog(n)), m = len(children), n = len(cookies)
    Space: O(1)
*/

class Solution {
    public int findContentChildren(int[] children, int[] cookies) {
        Arrays.sort(cookies);
        Arrays.sort(children);
        int res = 0, childCur = 0, len = children.length;
        for (int cookie : cookies) {
            if (cookie >= children[childCur]) {
                res++;
                childCur++;
            }
            if (childCur >= len) break;
        }
        return res;
    }
}

