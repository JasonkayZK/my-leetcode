/*
 * @lc app=leetcode.cn id=999 lang=java
 *
 * [999] 车的可用捕获量
 */

/* Method 1: Brute force

    Time: O(8*8)
    Space: O(1)
*/
class Solution {
    public int numRookCaptures(char[][] board) {
        int row = 0, col = 0;
        boolean find = false;
        for(row = 0; row < board.length && !find; ++row){
            for(col = 0; col < board.length && !find; ++col){
                if(board[row][col]=='R') find = true;
            }
        }
        --row;
        --col;

        int res = 0;
        for(int nrow = row - 1; nrow >= 0; --nrow){
            if(board[nrow][col] == 'p'){
                ++res;
                break;
            }
            if(board[nrow][col] == 'B') break;
        }
        for(int nrow = row + 1; nrow < board.length; ++nrow){
            if(board[nrow][col] == 'p'){
                ++res;
                break;
            }
            if(board[nrow][col] == 'B') break;
        }
        for(int ncol = col-1; ncol >= 0; --ncol){
            if(board[row][ncol] == 'p'){
                ++res;
                break;
            }
            if(board[row][ncol] == 'B') break;
        }
        for(int ncol = col+1; ncol < board[0].length; ++ncol){
            if(board[row][ncol] == 'p'){
                ++res;
                break;
            }
            if(board[row][ncol] == 'B') break;
        }
        return res;
    }
}
// @lc code=end


