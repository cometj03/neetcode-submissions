class Solution {
public:
    int trap(vector<int>& height) {
        int N = height.size();
        vector<int> R(N, -1), L(N, -1);
        stack<int> S;
        for (int i = 0; i < N; i++) {
            while (!S.empty() && height[S.top()] <= height[i]) {
                R[S.top()] = i;
                S.pop();
            }
            S.push(i);
        }
        S = {};
        for (int i = N - 1; i >= 0; i--) {
            while (!S.empty() && height[S.top()] < height[i]) {
                L[S.top()] = i;
                S.pop();
            }
            S.push(i);
        }

        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (R[i] == -1 || R[i] == i + 1) continue;
            int r = R[i], min_height = min(height[i], height[r]);
            int area = (r - i - 1) * min_height;
            for (int j = i + 1; j < r; j++) {
                area -= height[j];
                height[j] = min_height; // 블록으로 메우기
            }
            ans += area;
        }
        for (int i = N - 1; i >= 0; i--) {
            if (L[i] == -1 || L[i] == i - 1) continue;
            int l = L[i], min_height = min(height[i], height[l]);
            int area = (i - l - 1) * min_height;
            for (int j = i - 1; j > l; j--) {
                area -= height[j];
                height[j] = min_height;
            }
            ans += area;
        }

        return ans;
    }
};
