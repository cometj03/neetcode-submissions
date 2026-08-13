class Solution {
public:
    int trap(vector<int>& height) {
        int N = height.size();
        // i번째 칸에 담아둘 수 있는 물
        // = max(0, min(left_max, right_max) - height[i])
        vector<int> L(N, 0), R(N, 0);

        int m = 0;
        for (int i = 0; i < N; i++) {
            L[i] = m;
            m = max(m, height[i]);
        }
        m = 0;
        for (int i = N - 1; i >= 0; i--) {
            R[i] = m;
            m = max(m, height[i]);
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            ans += max(0, min(L[i], R[i]) - height[i]);
        }
        return ans;
    }
};
