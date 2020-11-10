import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=1260 lang=java
 *
 * [1260] 二维网格迁移
 */

/* Test Case:

[[1,2,3],[4,5,6],[7,8,9]]
1

*/

/* Method 1: Line Traverse

    Time: O(m * n)
    Extra Space: O(1)
*/
// @lc code=start
class Solution {
    //思路是：找到右移后数组第一个元素 在原来数组中的位置，从这里开始遍历元素加入列表，列满行+1，行满行归零
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        // 准备返回的列表
        List<List<Integer>> ret = new ArrayList<List<Integer>>();
        for(int i=0 ;i<grid.length;i++){
            ret.add(new ArrayList<>());
        }
        // 
        k = k%(grid.length*grid[0].length);
        // 如果k是二维数组元素个数的倍数,说明数组没有变化,直接返回
        if(k==0){
            for(int i=0 ;i<grid.length;i++){
                for(int j=0 ;j<grid[0].length;j++){
                    ret.get(i).add(grid[i][j]);
                }
            }  
        }    
        // 就像计算时钟时间一样进制计算数组中元素位置  
        else {
            int ColumnNum = grid.length;
            int RowNum = grid[0].length;
            // 数组右移几位,开始遍历的时候起始位置就是倒数几位
            int qishi= ColumnNum*RowNum-k;
            int line = qishi/grid[0].length;
            int row = qishi%grid[0].length;
            for(int i=0 ;i<grid.length;i++){
                for(int j=0 ;j<grid[0].length;j++){
                    ret.get(i).add(grid[line][row]);
                    row++;
                    // 进制
                    if(row==RowNum){
                        row = 0;
                        line++;
                    }
                    if(line==ColumnNum)
                        line=0;
                }
            }
        }
        return ret;
    }
}
// @lc code=end

