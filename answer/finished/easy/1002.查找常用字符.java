import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=1002 lang=java
 *
 * [1002] 查找常用字符
 *
 * https://leetcode-cn.com/problems/find-common-characters/description/
 *
 * algorithms
 * Easy (63.97%)
 * Likes:    38
 * Dislikes: 0
 * Total Accepted:    5.1K
 * Total Submissions: 8K
 * Testcase Example:  '["bella","label","roller"]'
 *
 * 给定仅有小写字母组成的字符串数组 A，返回列表中的每个字符串中都显示的全部字符（包括重复字符）组成的列表。例如，如果一个字符在每个字符串中出现 3
 * 次，但不是 4 次，则需要在最终答案中包含该字符 3 次。
 * 
 * 你可以按任意顺序返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：["bella","label","roller"]
 * 输出：["e","l","l"]
 * 
 * 
 * 示例 2：
 * 
 * 输入：["cool","lock","cook"]
 * 输出：["c","o"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= A.length <= 100
 * 1 <= A[i].length <= 100
 * A[i][j] 是小写字母
 * 
 * 
 */

/* Test Case:

["bella","label","roller"]
["cool","lock","cook"]

*/

/* Method 1: Brute Force: Two dict 

    Time: O(n)
    Space: O(1)
*/
class Solution {
    public List<String> commonChars(String[] A) {
        int[] res = new int[26];
        res = createDict(A[0]);
        for (int i = 1; i < A.length; ++i) {
            updateDict(res, createDict(A[i]));
        }

        List<String> answer = new ArrayList<>();
        for (char i = 0; i < res.length; ++i) {
            while(res[i]-- > 0) answer.add(Character.toString((char)('a' + i)));
        }
        return answer;
    }

    private int[] createDict(String str) {
        int[] res = new int[26];
        for (int c : str.toCharArray()) res[c - 'a']++;
        return res;
    }

    private void updateDict(int[] res, int[] temp) {
        for (int i = 0; i < res.length; ++i) res[i] = Math.min(res[i], temp[i]);
    }
}

