import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=744 lang=java
 *
 * [744] 寻找比目标字母大的最小字母
 */

/* Test Case:

["c", "f", "j"]
"a"
["c", "f", "j"]
"c"
["c", "f", "j"]
"d"
["c", "f", "j"]
"g"
["c", "f", "j"]
"j"
["c", "f", "j"]
"k"
["c", "c", "f", "f", "j", "j", "j"]
"k"

*/

/* Method 1: Remove Duplicate + Binary Search 

    Time: O(n + log(n))
    Space: O(1)

class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        // 0. 原地去重
        int len = 1;
        char cur = letters[0];
        for (int i = 1; i < letters.length; ++i) {
            if (letters[i] != cur) {
                cur = letters[i];
                letters[len++] = cur;
            }
        }
        letters = Arrays.copyOf(letters, len);
        
        // 1. 先缩短范围为(-inf, letters[0]) && [letters[len - 1], +inf)
        if (target < letters[0] || target >= letters[len - 1]) return letters[0];
        // 2. 再二分:
        int index = Arrays.binarySearch(letters, target);
        //  2.1. 二分找到, 返回 index + 1
        if (index >= 0 && index < len) return letters[index + 1];
        //  2.2. 二分没找到, 插入点index
        else if (index < 0) return letters[-index - 1];
        
        throw new RuntimeException("Result not found!");
    }
}
*/

/* Method 2: Binary Search 

    Time: O(log(n))
    Space: O(1)
*/
class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        if (letters[0] > target || letters[letters.length - 1] <= target) return letters[0];
        int left = 1, right = letters.length - 1, mid = (right - left) / 2 + left;
        while (left <= right) {
            mid = (right - left) / 2 + left;
            if (letters[mid] <= target) left = mid + 1;
            else {
                if (letters[mid - 1] <= target) return letters[mid];
                else right = mid - 1;
            }
        }

        throw new RuntimeException("Result not found!");
    }
}
