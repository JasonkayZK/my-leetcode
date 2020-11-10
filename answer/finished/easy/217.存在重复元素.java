import java.util.HashSet;
import java.util.Set;

/*
 * @lc app=leetcode.cn id=217 lang=java
 *
 * [217] 存在重复元素
 */

/* Test Case:

[]
[1]
[1,2,3,1]
[1,2,3,4]
[1,1,1,3,3,4,3,2,4,2]

*/

/* Method 1: Set 

    Time: O(n)
    Space: O(n)
*/

class Solution {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int n : nums) {
            if (set.contains(n)) return true;
            set.add(n);
        }
        return false;

    }
}

