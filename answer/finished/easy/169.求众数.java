import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/*
 * @lc app=leetcode.cn id=169 lang=java
 *
 * [169] 求众数
 *
 * https://leetcode-cn.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (60.27%)
 * Likes:    298
 * Dislikes: 0
 * Total Accepted:    62.3K
 * Total Submissions: 103.5K
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
 * 
 * 你可以假设数组是非空的，并且给定的数组总是存在众数。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,3]
 * 输出: 3
 * 
 * 示例 2:
 * 
 * 输入: [2,2,1,1,1,2,2]
 * 输出: 2
 * 
 * 
 */

/* Test Case:

[1]
[3,2,3]
[2,2,1,1,1,2,2]
[1,2,2]
[1,2,3,4,5,5,5,5,5]

*/

/* Method 1: HashTable 

    Time Complexity: O(n)
    Space Complexity: O(n)

class Solution {
    public int majorityElement(int[] nums) {
        if (nums == null || nums.length == 0) {throw new RuntimeException("Array is not empty!");}
        if (nums.length == 1) {return nums[0];}

        Map<Integer, Integer> map = new HashMap<>(nums.length);

        int limit = nums.length / 2;
        int time = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (map.containsKey(nums[i])) {
                time = map.get(nums[i]) + 1;
                if (time > limit) {return nums[i];}
                map.put(nums[i], time);
            } else {
                map.put(nums[i], 1);
            }
        }

        throw new RuntimeException("Result is always Exist!");
    }
}
*/

/* Method 2: Sort 

    Time: O(nlog(n))
    Space: O(1)

class Solution {
    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
        return nums[nums.length / 2];
    }
}
*/

/* Method 3: Moore Voting [Best]

    Time: O(n)
    Space: O(1)
*/
class Solution {
    public int majorityElement(int[] nums) {
        int count = 0, curNum = 0;
        for (int num : nums) {
            if (count == 0) {
                curNum = num;
            }
            if (num != curNum) {
                count--;
            } else {
                count++;
            }
        }
        return curNum;

    }
}

