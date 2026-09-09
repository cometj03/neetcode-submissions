class Solution {
public:
    int decide(vector<int>& piles, int h, int k) {
        int ret = 0;
        for (int p : piles) ret += (p + k - 1) / k;
        return ret <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 1e9;
        // NNNNNN'Y'YYY
        while (l < r) {
            int m = (l + r) >> 1;
            if (decide(piles, h, m)) r = m;
            else l = m + 1;
        }
        return l;
    }
};
