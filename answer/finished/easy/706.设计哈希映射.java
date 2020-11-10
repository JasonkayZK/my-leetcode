import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=706 lang=java
 *
 * [706] 设计哈希映射
 */

/* Test Case:

["MyHashMap","put","put","get","get","put","get", "remove", "get"]
[[],[1,1],[2,2],[1],[3],[2,3],[2],[2],[2]]

*/

/* Method 1: Array

    put: O(1)
    get: O(1)
    remove: O(1)

    Space: O(max)

class MyHashMap {

    private int[] arr;

    public MyHashMap() {
        arr = new int[1000000 + 1];
        Arrays.setAll(arr, x -> -1);
    }
    
    public void put(int key, int value) {
        arr[key] = value;
    }
    
    public int get(int key) {
        return arr[key];
    }
    
    public void remove(int key) {
        arr[key] = -1;
    }
}
*/


/* Method 2: Zip-Array

    put: O(log(len))
    get: O(log(len))
    remove: O(log(len))

    Space: O(max)
*/
class MyHashMap {

    class Node {
        public int key;
        public int val;
        public Node next;

        public Node(int key, int val) {
            this.key = key;
            this.val = val;
            next = null;
        }
    }

    private int len = 1000;

    Node[] arr;

    public MyHashMap() {
        arr = new Node[len];
        Arrays.setAll(arr, x -> new Node(-1, -1));
    }

    public void put(int key, int value) {
        Node cur = arr[key % len], prev = null;
        
        while (cur != null) {
            if (cur.key == key) {
                cur.val = value;
                return;
            }
            prev = cur;
            cur = cur.next;
        }

        Node node = new Node(key, value);
        prev.next = node;
    }
    
    public int get(int key) {
        Node cur = arr[key % len];
        while (cur != null) {
            if (cur.key == key) return cur.val;
            cur = cur.next;
        }

        return -1;
    }

    public void remove(int key) {
        Node cur = arr[key % len];

        while (cur != null) {
            if (cur.key == key) {
                cur.val = -1;
            }
            cur = cur.next;
        }
    }

}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */

