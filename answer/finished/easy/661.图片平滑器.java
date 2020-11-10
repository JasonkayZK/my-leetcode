/*
 * @lc app=leetcode.cn id=661 lang=java
 *
 * [661] 图片平滑器
 */

/* Test Case:

[[1,1,1],[1,0,1],[1,1,1]]
[[1,1,1],[1,5,1],[1,1,1]]
[[1,3,2],[4,5,12],[2,5,1]]

*/

/* Method 1: Brute Force

    Time: O(r * c)
    Space: O(r * c)

class Solution {
    public int[][] imageSmoother(int[][] M) {
        int[][] res = new int[M.length][M[0].length];
        
        for (int i = 0; i < M.length; ++i) {
            for (int j = 0; j < M[0].length; ++j) {
                res[i][j] = smooth(M, res, i, j);
            }
        }
        return res;
    }

    private int smooth(int[][] M, int[][] res, int i, int j) {
        int r = M.length, c = M[0].length;
        int count = 0, sum = 0;
        if (isValid(i - 1, j - 1, r, c)) {
            count++;
            sum += M[i - 1][j - 1];
        }
        if (isValid(i - 1, j, r, c)) {
            count++;
            sum += M[i - 1][j];
        }
        if (isValid(i - 1, j + 1, r, c)) {
            count++;
            sum += M[i - 1][j + 1];
        }
        if (isValid(i, j - 1, r, c)) {
            count++;
            sum += M[i][j - 1];
        }
        if (isValid(i, j, r, c)) {
            count++;
            sum += M[i][j];
        }
        if (isValid(i, j + 1, r, c)) {
            count++;
            sum += M[i][j + 1];
        }
        if (isValid(i + 1, j - 1, r, c)) {
            count++;
            sum += M[i + 1][j - 1];
        }
        if (isValid(i + 1, j, r, c)) {
            count++;
            sum += M[i + 1][j];
        }
        if (isValid(i + 1, j + 1, r, c)) {
            count++;
            sum += M[i + 1][j + 1];
        }

        return (int)Math.floor(sum / count);
    }

    private boolean isValid(int i, int j, int r, int c) {
        return i >= 0 && i < r && j >= 0 && j < c;
    }

}
*/

/* Method 2: Non-Inplace

    Time: O(r * c)
    Space: O(1)
*/
class Solution {
    int row = 0;
    int col = 0;
    // 上、下、左、右，上左，上右，下左，下右
    int dirR[] = {-1,1,0,0,-1,-1,1,1};
    int dirC[] = {0,0,-1,1,-1,1,-1,1};

    public int[][] imageSmoother(int[][] M) {
        if (M == null || M.length < 1 || M[0] == null || M[0].length < 1) {
            return null;
        }
        
        row = M.length;
        col = M[row - 1].length;
        
        int ans[][] = new int[row][col];
        
        for (int i = 0;i < row;i++) {
            for (int j = 0;j < col;j++) {
                ans[i][j] = calcul(M,i,j);
            }
        }
        
        return ans;
    }


    
    private int calcul(int arr[][],int i,int j) {
        int count = 1;
        int sum = arr[i][j];
        
        for (int k = 0;k < dirR.length;k++) {
            int nextR = i + dirR[k];
            int nextC = j + dirC[k];
            
            if (nextR >= 0 && nextR < row && nextC >= 0 && nextC < col) {
                count++;
                sum += arr[nextR][nextC];
            }
        }
        
        return sum / count;
    }
}

