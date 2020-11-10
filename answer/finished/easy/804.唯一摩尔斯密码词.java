import java.util.HashSet;
import java.util.Set;

/*
 * @lc app=leetcode.cn id=804 lang=java
 *
 * [804] 唯一摩尔斯密码词
 */

/* Test Case:



*/

/* Method 1: Brute Force: Set


    Time: O(sum(i * len(i))) 
    Space: O(n)
*/
class Solution {

    private static final String[] dict = new String[] {
        ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
    };

    public int uniqueMorseRepresentations(String[] words) {
        Set<String> set = new HashSet<>(words.length + 1);
        
        StringBuilder sb = null;
        for (String str : words) {
            sb = new StringBuilder();
            for (char c : str.toCharArray()) {
                sb.append(dict[c - 'a']);
            }
            set.add(sb.toString());
        }
        return set.size();
    }
}

