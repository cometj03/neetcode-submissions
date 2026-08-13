class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int N = heights.size();
        // L[i]: A[i]의 왼쪽에 있으면서 A[i]보다 작으면서 가장 오른쪽에 있는 원소의 위치
        // R[i]: A[i]의 오른쪽에 있으면서 A[i]보다 작으면서 가장 왼쪽에 있는 원소의 위치
        vector<int> L(N, -1), R(N, N);
        stack<int> S;
        for (int i = 0; i < N; i++) {
            while (!S.empty() && heights[S.top()] > heights[i]) {
                R[S.top()] = i;
                S.pop();
            }
            S.push(i);
        }

        S = {};
        for (int i = N - 1; i >= 0; i--) {
            while (!S.empty() && heights[S.top()] > heights[i]) {
                L[S.top()] = i;
                S.pop();
            }
            S.push(i);
        }

        int ans = 0;
        for (int i = 0; i < N; i++) {
            ans = max(ans, heights[i] * (R[i] - L[i] - 1));
        }
        return ans;
    }
};
