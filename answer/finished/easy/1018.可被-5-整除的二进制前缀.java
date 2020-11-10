import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=1018 lang=java
 *
 * [1018] 可被 5 整除的二进制前缀
 */

/* Test Case:

[0]
[1]
[1,0]
[0,1,1]
[1,1,1]
[0,1,1,1,1,1]
[1,1,1,0,1]

*/

/* Method 1: Bit Operation + Mod */
class Solution {
    public List<Boolean> prefixesDivBy5(int[] A) {
        List<Boolean> res = new ArrayList<>(A.length);

        int cur = 0;
        for (int i = 0; i < A.length; ++i) {
            cur = (cur << 1) % 5 + A[i];
            res.add(cur % 5 == 0);
        }
        return res;
    }
}

