/*
 * @lc app=leetcode.cn id=412 lang=java
 *
 * [412] Fizz Buzz
 *
 * https://leetcode-cn.com/problems/fizz-buzz/description/
 *
 * algorithms
 * Easy (60.82%)
 * Likes:    32
 * Dislikes: 0
 * Total Accepted:    18.2K
 * Total Submissions: 29.9K
 * Testcase Example:  '1'
 *
 * 写一个程序，输出从 1 到 n 数字的字符串表示。
 * 
 * 1. 如果 n 是3的倍数，输出“Fizz”；
 * 
 * 2. 如果 n 是5的倍数，输出“Buzz”；
 * 
 * 3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”。
 * 
 * 示例：
 * 
 * n = 15,
 * 
 * 返回:
 * [
 * ⁠   "1",
 * ⁠   "2",
 * ⁠   "Fizz",
 * ⁠   "4",
 * ⁠   "Buzz",
 * ⁠   "Fizz",
 * ⁠   "7",
 * ⁠   "8",
 * ⁠   "Fizz",
 * ⁠   "Buzz",
 * ⁠   "11",
 * ⁠   "Fizz",
 * ⁠   "13",
 * ⁠   "14",
 * ⁠   "FizzBuzz"
 * ]
 * 
 * 
 */
class Solution {
    public List<String> fizzBuzz(int n) {
      List<String> res = new ArrayList<>();
      int F=1, B=1;
      // solution 2: using count instead of %;
      for (int i=1; i <= n; i++) {
        if (F != 3 && B != 5) {
          res.add(String.valueOf(i));
          F++;
          B++;
        }
        else if (F == 3 && B == 5) {
          res.add("FizzBuzz");
          F = 1;
          B = 1;
        }
        else if (F == 3) {
          res.add("Fizz");
          F = 1;
          B++;
        }
        else {
          res.add("Buzz");
          B = 1;
          F++;
        }  
      }
      return res;
    }
  }
