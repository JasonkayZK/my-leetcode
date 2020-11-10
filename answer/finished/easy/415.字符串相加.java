/*
 * @lc app=leetcode.cn id=415 lang=java
 *
 * [415] 字符串相加
 */

/* Test Case:

"123421343245"
"12351245234512341234358906"
"1230589234340927230587203457283045"
"123590732485073240957120347120857913804578032945873290457032945798127348902134"

*/

/* Method 1: Big Number add 

    Time: O(max(m, n))
    Space: O(max(m, n))

*/
class Solution {
    public String addStrings(String num1, String num2) {
        StringBuilder sb = new StringBuilder(5105);
        int carry = 0, temp = 0;
        int cur1 = num1.length() - 1, cur2 = num2.length() - 1;

        while (cur1 >= 0 || cur2 >= 0 || carry > 0) {
            temp = carry;
            if (cur1 >= 0) temp += num1.charAt(cur1--) - '0';
            if (cur2 >= 0) temp += num2.charAt(cur2--) - '0';
            carry = temp / 10;
            sb.append(temp % 10);
        }
        return sb.reverse().toString();
    }
}

