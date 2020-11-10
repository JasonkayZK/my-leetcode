import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*
 * @lc app=leetcode.cn id=260 lang=java
 *
 * [260] 只出现一次的数字 III
 */

/* Test Case:

[1,2,1,3,2,5]

*/

/* Method 1: HashMap

    Time: O(nlogn)
    Space: < O(n)

class Solution {
    public int[] singleNumber(int[] nums) {
        List<Integer> res = new ArrayList<>(2);
        Map<Integer, Integer> map = new HashMap<>();
        for (int n : nums) {
            map.put(n, map.getOrDefault(n, 0) + 1);
        }

        for (int n : map.keySet()) {
            if (map.get(n) == 1) res.add(n);
        }

        return new int[] {res.get(0), res.get(1)};
    }
}
*/

/* Method 2: Bit Manipulation

    Time: O(2n)
    Space: O(1)
*/
class Solution {
    public int[] singleNumber(int[] nums) {
        int mask = 0;
        for (int n : nums) mask ^= n;
        mask = mask & (~mask + 1);
        
        int[] res = new int[2];
        for (int n : nums) {
            if ((n & mask) == 0) {
                res[0] ^= n;
            } else {
                res[1] ^= n;
            }
        }
        return res;
    }
}


