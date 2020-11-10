import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=830 lang=java
 *
 * [830] 较大分组的位置
 *
 * https://leetcode-cn.com/problems/positions-of-large-groups/description/
 *
 * algorithms
 * Easy (43.16%)
 * Likes:    28
 * Dislikes: 0
 * Total Accepted:    5.1K
 * Total Submissions: 11.7K
 * Testcase Example:  '"abbxxxxzzy"'
 *
 * 在一个由小写字母构成的字符串 S 中，包含由一些连续的相同字符所构成的分组。
 * 
 * 例如，在字符串 S = "abbxxxxzyy" 中，就含有 "a", "bb", "xxxx", "z" 和 "yy" 这样的一些分组。
 * 
 * 我们称所有包含大于或等于三个连续字符的分组为较大分组。找到每一个较大分组的起始和终止位置。
 * 
 * 最终结果按照字典顺序输出。
 * 
 * 示例 1:
 * 
 * 
 * 输入: "abbxxxxzzy"
 * 输出: [[3,6]]
 * 解释: "xxxx" 是一个起始于 3 且终止于 6 的较大分组。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: "abc"
 * 输出: []
 * 解释: "a","b" 和 "c" 均不是符合要求的较大分组。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: "abcdddeeeeaabbbcd"
 * 输出: [[3,5],[6,9],[12,14]]
 * 
 * 说明:  1 <= S.length <= 1000
 * 
 */

/* Test Case 

"a"
"aa"
"aab"
"aaa"
"abbxxxxzzy"
"abc"
"abcdddeeeeaabbbcd"

*/

/* Method 1: Two Pointer: fast-slow, len + cur

    Time: O(n)
    Space: O(1)
*/
class Solution {
    public List<List<Integer>> largeGroupPositions(String S) {
        if (S.length() < 3) return new ArrayList<>();

        List<List<Integer>> res = new ArrayList<>();
        char cur = 0;
        char[] arr = S.toCharArray();
        int len = 0;
        for (int slow = 0, fast = 0; fast < arr.length; slow = fast) {
            cur = arr[slow];
            len = 0;
            while (fast < arr.length && arr[fast] == cur) fast++;
            if (fast - slow >= 3) {
                List<Integer> temp = new ArrayList<>(2);
                temp.add(slow);
                temp.add(fast - 1);
                res.add(temp);
            }
        }
        return res;
    }
}

