impl Solution {
    pub fn rotate(nums: &mut Vec<i32>, k: i32) {
        let n = nums.len();
        let kk = k as usize % n;
        if kk == 0 {
            return;
        }
        Self::reverse(nums, 0, n - 1);
        Self::reverse(nums, 0, kk - 1);
        Self::reverse(nums, kk, n - 1);
    }

    fn reverse(nums: &mut Vec<i32>, mut s: usize, mut e: usize) {
        while s < e {
            let mut tmp = nums[s];
            nums[s] = nums[e];
            nums[e] = tmp;
            s += 1;
            e -= 1;
        }
    }
}
