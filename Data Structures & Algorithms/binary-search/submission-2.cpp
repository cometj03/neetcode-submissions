class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = (l + r) >> 1;
            if (nums[m] >= target) r = m;
            else l = m + 1;
        }
        return target == nums[l] ? l : -1;
    }
};
