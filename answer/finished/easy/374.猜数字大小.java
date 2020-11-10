/*
 * @lc app=leetcode.cn id=374 lang=java
 *
 * [374] 猜数字大小
 */
/* The guess API is defined in the parent class GuessGame.
   @param num, your guess
   @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
      int guess(int num); */

/*  Test Case:

10
6
5
3
1
1
3
2
3
3

*/

/* Method 1: Binary Search [Iteration]

    Time: O(log(n))
    Space: O(1)

public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int left = 1, right = n, mid = (right - left) / 2 + left;
        while (left <= right) {
            mid = (right - left) / 2 + left;
            int result = guess(mid);
            if (result == 0) return mid;
            else if (result < 0) {right = mid - 1;}
            else left = mid + 1;
        }       
        return right;
    }
}
*/

/* Method 2: Binary Search [Recursive] */
public class Solution extends GuessGame {
    public int guessNumber(int n) {
        return binarySearch(1, n);
    }

    private int binarySearch(int start, int end) {
        if (start == end) {return start;}
        int mid = (end - start) / 2 + start;
        int result = 0, query = -2;
        query = guess(mid);
        if (query == 0) result = mid;
        else if (query == 1) result = binarySearch(mid + 1, end);
        else result = binarySearch(start, mid - 1);
        
        return result;
       }
}

