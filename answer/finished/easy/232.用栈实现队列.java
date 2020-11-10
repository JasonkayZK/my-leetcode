import java.util.Stack;

/*
 * @lc app=leetcode.cn id=232 lang=java
 *
 * [232] 用栈实现队列
 *
 * https://leetcode-cn.com/problems/implement-queue-using-stacks/description/
 *
 * algorithms
 * Easy (60.90%)
 * Likes:    91
 * Dislikes: 0
 * Total Accepted:    18.2K
 * Total Submissions: 29.9K
 * Testcase Example:  '["MyQueue","push","push","peek","pop","empty"]\n[[],[1],[2],[],[],[]]'
 *
 * 使用栈实现队列的下列操作：
 * 
 * 
 * push(x) -- 将一个元素放入队列的尾部。
 * pop() -- 从队列首部移除元素。
 * peek() -- 返回队列首部的元素。
 * empty() -- 返回队列是否为空。
 * 
 * 
 * 示例:
 * 
 * MyQueue queue = new MyQueue();
 * 
 * queue.push(1);
 * queue.push(2);  
 * queue.peek();  // 返回 1
 * queue.pop();   // 返回 1
 * queue.empty(); // 返回 false
 * 
 * 说明:
 * 
 * 
 * 你只能使用标准的栈操作 -- 也就是只有 push to top, peek/pop from top, size, 和 is empty
 * 操作是合法的。
 * 你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
 * 假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）。
 * 
 * 
 */

/* Test Case:

["MyQueue","push","push","push","peek"]
[[],[1],[2],[3],[]]

*/

/* Method 1: Two Stack

    Time:
        push: O(n)
        pop: O(1)
        peek: O(1)
        empty: O(1)

    Space:
        O(2*n)
*/
class MyQueue {
    Stack<Integer> stackPush;
    Stack<Integer> stackPop;
    /** Initialize your data structure here. */
    public MyQueue() {
        stackPush = new Stack<Integer>();
        stackPop = new Stack<Integer>();
    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
        stackPush.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        if(stackPush.empty() && stackPop.empty()){
            throw new RuntimeException("queue is empty");
        }else if(stackPop.empty()){
            //把第一个栈中的数据转到第二个栈中;
            while(!stackPush.empty()){
                stackPop.push(stackPush.pop());
            }
        }
        
        return stackPop.pop();
    }
    
    /** Get the front element. */
    public int peek() {
        if(stackPop.empty() && stackPush.empty()){
            throw new RuntimeException("queue is empty");
        }else if(stackPop.empty()){//stackPop 必须为空才可以;
            while(!stackPush.empty()){
                stackPop.push(stackPush.pop());
            }
            
        }
        return stackPop.peek();
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
        if(stackPop.empty() && stackPush.empty()){
            return true;
        }
        return false;
    }
    
     public static void main(String[] args){
      MyQueue obj = new MyQueue();
      obj.push(1);
      int param_3 = obj.peek();
      int param_2 = obj.pop();
      
      boolean param_4 = obj.empty();
      System.out.println(param_3);
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */

