class Solution {
    /**
     * @param {number[]} nums
     * @return {boolean}
     */
    hasDuplicate(nums) {
        const d = {};
        for (const i of nums) {
            if (d[i]) return true;
            d[i] = 1;
        }
        return false;
    }
}
