import java.util.HashMap;
import java.util.Map;

/*
 * @lc app=leetcode.cn id=690 lang=java
 *
 * [690] 员工的重要性
 */
/*
// Employee info
class Employee {
    // It's the unique id of each node;
    // unique id of this employee
    public int id;
    // the importance value of this employee
    public int importance;
    // the id of direct subordinates
    public List<Integer> subordinates;
};
*/

/* Test Case:



*/
/* Method 1: HashMap + DFS 

    Time: O(n)
    Space: O(n)
*/
class Solution {
    public int getImportance(List<Employee> employees, int id) {
        Map<Integer, Employee> emap = new HashMap<>();
        for (Employee e : employees) emap.put(e.id, e);
        return dfs(emap, id);
    }

    public int dfs (Map<Integer, Employee> map, int eid) {
            Employee employee = map.get(eid);
            int ans = employee.importance;
            for (Integer id : employee.subordinates) {
                ans += dfs(map, id);
            }
            return ans;
    }
}

