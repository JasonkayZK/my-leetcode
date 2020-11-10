import java.util.HashSet;
import java.util.Set;

/*
 * @lc app=leetcode.cn id=997 lang=java
 *
 * [997] 找到小镇的法官
 *
 * https://leetcode-cn.com/problems/find-the-town-judge/description/
 *
 * algorithms
 * Easy (46.61%)
 * Likes:    23
 * Dislikes: 0
 * Total Accepted:    4.4K
 * Total Submissions: 9.4K
 * Testcase Example:  '2\n[[1,2]]'
 *
 * 在一个小镇里，按从 1 到 N 标记了 N 个人。传言称，这些人中有一个是小镇上的秘密法官。
 * 
 * 如果小镇的法官真的存在，那么：
 * 
 * 
 * 小镇的法官不相信任何人。
 * 每个人（除了小镇法官外）都信任小镇的法官。
 * 只有一个人同时满足属性 1 和属性 2 。
 * 
 * 
 * 给定数组 trust，该数组由信任对 trust[i] = [a, b] 组成，表示标记为 a 的人信任标记为 b 的人。
 * 
 * 如果小镇存在秘密法官并且可以确定他的身份，请返回该法官的标记。否则，返回 -1。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：N = 2, trust = [[1,2]]
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 输入：N = 3, trust = [[1,3],[2,3]]
 * 输出：3
 * 
 * 
 * 示例 3：
 * 
 * 输入：N = 3, trust = [[1,3],[2,3],[3,1]]
 * 输出：-1
 * 
 * 
 * 示例 4：
 * 
 * 输入：N = 3, trust = [[1,2],[2,3]]
 * 输出：-1
 * 
 * 
 * 示例 5：
 * 
 * 输入：N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
 * 输出：3
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= N <= 1000
 * trust.length <= 10000
 * trust[i] 是完全不同的
 * trust[i][0] != trust[i][1]
 * 1 <= trust[i][0], trust[i][1] <= N
 * 
 * 
 */

/* Test Case:

2
[[1,2]]
3
[[1,3],[2,3]]
3
[[1,3],[2,3],[3,1]]
3
[[1,2],[2,3]]
3
[[2,3],[1,2]]
4
[[1,3],[1,4],[2,3],[2,4],[4,3]]
4
[[4,3],[2,4],[2,3],[1,4],[1,3]]

*/

/* Method 1: Degree 

    Time: O(2N)
    Space: O(N)
*/
class Solution {
    public int findJudge(int N, int[][] trust) {
        int[] cnt = new int[N + 1];
        for (int[] pair : trust) {
            cnt[pair[0]]--;
            cnt[pair[1]]++;
        }
        for (int i = 1; i <= N; ++i) {
            if (cnt[i] == N - 1) return i;
        }
        return -1;
    }         
}

