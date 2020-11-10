/*
 * @lc app=leetcode.cn id=507 lang=java
 *
 * [507] 完美数
 */

/* Test Case:

1
2
6
26
25
28
256

*/

/* Method 1: Brute Force: Sqrt 

    Time: O(sqrt(n))
    Space: O(1)
*/
class Solution {
    public boolean checkPerfectNumber(int num) {
        if (num <= 1) {return false;}

        int sum = 1, boundary = (int)Math.floor(Math.sqrt(num));
        int index = 2;
        while (index <= boundary) {
            if (num % index == 0) {
                sum += index;
                sum += num / index;
            }
            index++;
        }
        
        return sum == num;
    }
}

