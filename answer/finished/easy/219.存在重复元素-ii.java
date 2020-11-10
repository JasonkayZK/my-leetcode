import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/*
 * @lc app=leetcode.cn id=219 lang=java
 *
 * [219] 存在重复元素 II
 */

/* Test Case:

[1,2,3,1]
3
[1,0,1,1]
1
[1,2,3,1,2,3]
2

*/

/* Method 1: HashMap 

    Time: O(n)
    Space: O(n)

class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; ++i) {
            if (map.containsKey(nums[i]) && i - map.get(nums[i]) <= k) return true;
            else map.put(nums[i], i);
        }
        return false;
    }
}
*/

/* Method 2: Set [Better]

    Time: O(n)
    Space: O(n)
*/
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < nums.length; ++i) {
            if (i > k) set.remove(nums[i - k - 1]);
            if (!set.add(nums[i])) return true;
        }
        return false;
        
    }
}

