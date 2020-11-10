/*
 * @lc app=leetcode.cn id=705 lang=java
 *
 * [705] 设计哈希集合
 */

/* Method 1: Array

    add: O(1)
    contains(1)
    remove(1)

    Space: O(max)

class MyHashSet {

    boolean[] arr;

    public MyHashSet() {
        arr = new boolean[1000000 + 1];
    }
    
    public void add(int key) {
        arr[key] = true;
    }
    
    public void remove(int key) {
        arr[key] = false;
    }
    
    public boolean contains(int key) {
        return arr[key];
    }
}
*/


/* Method 2: Zip-Arr with Scott

    Time: O(log(len))
    Space: << O(max)
*/
class MyHashSet {

    class Node {
        public int val;

        public Node next;

        public Node (int val) {
            this.val = val;
            next = null;
        }
    }

    private static final int len = 100;

    private Node[] arr;

    public MyHashSet() {
        arr = new Node[len];
        for (int i = 0; i < len; ++i) {
            arr[i] = new Node(-1);
        }
    }
    
    public void add(int key) {
        int n = key % len;

        Node pre = arr[n];
        while (pre.next != null) {
            if (pre.next.val == key) return;
            pre = pre.next;
        }
        pre.next = new Node(key);
    }
    
    public void remove(int key) {
        int n = key % len;
        Node pre = arr[n];

        while (pre.next != null) {
            if (pre.next.val == key) {
                pre.next = pre.next.next;
                return;
            }
            pre = pre.next;
        }
    }
    
    public boolean contains(int key) {
        int n = key % len;
        Node cur = arr[n].next;
        while (cur != null) {
            if (cur.val == key) return true;
            cur = cur.next;
        }        
        return false;
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */

