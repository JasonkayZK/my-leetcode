/*
 * @lc app=leetcode.cn id=849 lang=java
 *
 * [849] 到最近的人的最大距离
 */


/* Test Case:

[1,0]
[1,0,0]
[1,0,0,0,0,0,0,0]
[1,0,0,0,1]
[1,0,0,0,0,1]
[1,0,0,0,1,0,1]
[1,0,0,0]
[0,1]
[0,0,0,0,0,0,1]
[0,0,0,1]
[0,0,1,0,1,1]

*/

/* Method 1: Linear Search: two-pointer

    Time: O(n)
    Space: O(1)
*/
class Solution {
    public int maxDistToClosest(int[] seats) {
        int count1 = 0;
        int count2 = 0;
        int i = 0, j = seats.length-1;
        // count1记录开头连续0的个数
        while(seats[i] == 0){
            count1++;
            i++;
        }
        // count2记录结尾连续0的个数
        while(seats[j] == 0){
            count2++;
            j--;
        }
        // countmax记录从第一个1到最后一个1之间，连续0的最大值
        int countmid = 0, countmax = 0;
        for(int k = i+1; k <= j; k++){
            if(seats[k] == 0){
                countmid++;
            }else{
                countmax = Math.max(countmax, countmid);
                countmid = 0;
            }
        }
        // 返回count1, count2, (countmax+1)/2三者中最大值
        return Math.max(Math.max(count1, count2), (countmax+1)/2);
    }
}


