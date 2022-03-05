use std::cmp::max;

impl Solution {
    pub fn find_lu_slength(a: String, b: String) -> i32 {
        if a.len() == b.len() {
            if a == b {
                -1
            } else {
                a.len() as i32
            }
        } else {
            max(a.len(), b.len()) as i32
        }
    }
}
