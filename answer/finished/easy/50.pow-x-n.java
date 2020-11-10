/*
 * @lc app=leetcode.cn id=50 lang=java
 *
 * [50] Pow(x, n)
 */

/* Test Case:

2.00000
10
2.10000
3
2.00000
-2
2.00000
-2147483648

*/

/* Method 1: Java API 
class Solution {
    public double myPow(double x, int n) {
        return Math.pow(x, n);
    }
}
*/

/* Method 2: Fast Pow */
class Solution {
    public double myPow(double x, int n) {
        if(n == 0) return 1;
            
        double temp = myPow(x,n/2);
    
        if(n%2 == 0) {return temp*temp;}
        return n > 0 ? x*temp*temp : (temp*temp)/x;      
    }
}
