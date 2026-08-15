impl Solution {
    pub fn daily_temperatures(temps: Vec<i32>) -> Vec<i32> {
        let mut stack: Vec<usize> = Vec::new();
        let mut ret = vec![0; temps.len()];
        for (i, t) in temps.iter().enumerate() {
            while let Some(&top) = stack.last() {
                if temps[top] >= *t {
                    break;
                }
                ret[stack.pop().unwrap()] = (i - top) as i32;
            }
            stack.push(i);
        }
        ret
    }
}
