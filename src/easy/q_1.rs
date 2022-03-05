use std::collections::HashMap;

struct Solution {}

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map = HashMap::new();

        for (idx, x) in nums.iter().enumerate() {
            if map.contains_key(&(target - x)) {
                return vec![*map.get(&(target - x)).unwrap() as i32, idx as i32];
            }
            map.insert(*x, idx);
        }

        return vec![];
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn q_1_test() {
        assert_eq!(Solution::two_sum(vec![2, 7, 11, 15], 9), vec![0, 1]);
        assert_eq!(Solution::two_sum(vec![3, 2, 4], 6), vec![1, 2]);
        assert_eq!(Solution::two_sum(vec![3, 3], 6), vec![0, 1]);
    }
}
