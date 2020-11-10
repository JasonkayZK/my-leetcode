import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/*
 * @lc app=leetcode.cn id=989 lang=java
 *
 * [989] 数组形式的整数加法
 */

/* Test Case:

[1,2,0,0]
34
[2,7,4]
181
[2,1,5]
806
[9,9,9,9,9,9,9,9,9,9]
1
[0]
23
[0]
10000


*/

/* Method 1:

    Time: O(A.length)
    Space: O(1)
*/

class Solution {
    public List<Integer> addToArrayForm(int[] A, int K) {
        List<Integer> res = new ArrayList<>(A.length + 1);
        int cur = A.length - 1;
        for (; cur >= 0; cur--) {
            if (K == 0) break;
            K += A[cur];
            res.add(K % 10);
            K /= 10;
        }

        while (cur >= 0) res.add(A[cur--]);
        while (K != 0) { 
            res.add(K % 10);
            K /= 10;
        }

        Collections.reverse(res); 
        return res;
    }
}

