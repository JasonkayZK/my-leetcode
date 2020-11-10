import java.util.Map;

/*
 * @lc app=leetcode.cn id=1207 lang=java
 *
 * [1207] 独一无二的出现次数
 */

/* Test Case:

[1,2,2,1,1,3]
[1,2]
[-3,0,1,-3,1,1,1,-3,10,0]

*/

/* Method 1: HashMap + HashSet

    Time: > O(n)
    Space: O(n)
*/

class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        Set<Integer> set = new HashSet<Integer>();
        
        // 记录出现次数
        for(int data :arr) map.put(data, map.getOrDefault(data, 0) + 1);
        
        // 验证重复值
        for(Integer i : map.values()) {
            if (!set.add(i)) return false;
        }
        return true;
    }
}
// @lc code=end

