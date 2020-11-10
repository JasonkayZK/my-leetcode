/*
 * @lc app=leetcode.cn id=1128 lang=java
 *
 * [1128] 等价多米诺骨牌对的数量
 */

/* Test Case:

[[1,2],[2,1],[3,4],[5,6]]

*/

/* Method 1: Brute Force [TLE]

    Time: O(n ^ 2)
    Space: O(1)

class Solution {
    public int numEquivDominoPairs(int[][] dominoes) {
        int res = 0;
        for (int i = 0; i < dominoes.length; ++i) {
            for (int j = i + 1; j < dominoes.length; ++j) {
                if (isPair(dominoes[i], dominoes[j])) res++;
            } 
        }

        return res;
    }

    private boolean isPair(int[] arr1, int[] arr2) {
        return (arr1[0] == arr2[0] && arr1[1] == arr2[1]) || (arr1[0] == arr2[1] && arr1[1] == arr2[0]);
    }
}
*/

/* Method 2: HashMap 

    Time: O(n)
    Space: O(n)
*/
class Solution {
    public int numEquivDominoPairs(int[][] dominoes) {
        int[] dict = new int[100];

        for (int[] one : dominoes) {
            int pair = Math.min(one[0], one[1]) * 10 + Math.max(one[0], one[1]);
            dict[pair]++;
        }

        int res = 0;
        for (int n : dict) {
            res += (-n + n * n) / 2;
        }
        return res;
    }

}

