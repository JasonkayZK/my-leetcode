/* Method 2: Number */
impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        if x == 0 {
            return true;
        }
        if x.is_negative() || x % 10 == 0 {
            return false;
        }

        let mut reversed = 0;
        let mut x = x;
        while x > reversed {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }

        return x == reversed || x == reversed / 10;
    }
}

/* Method 1: String

impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        let x_str = x.to_string();
        let x_str_reverse = x_str.chars().rev().collect::<String>();
        x_str == x_str_reverse
    }
}

 */
