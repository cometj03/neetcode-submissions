class Solution {
public:
    vector<int> T;
    void init(vector<int>& A, int node, int s, int e) {
        if (s == e) {
            T[node] = A[s - 1]; // 0-based index
            return;
        }
        int m = (s + e) / 2;
        init(A, node*2, s, m);
        init(A, node*2 + 1, m + 1, e);
        T[node] = max(T[node*2], T[node*2 + 1]);
    }

    // [l, r]: 구하려는 구간
    // node: seg tree 방문 노드
    // [s, e]: node가 관할하는 범위
    int getMax(int l, int r, int node, int s, int e) {
        if (r < s || e < l) return INT_MIN;
        if (l <= s && e <= r) return T[node];

        int m = (s + e) / 2;
        return max(getMax(l, r, node*2, s, m), getMax(l, r, node*2 + 1, m + 1, e));
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        T.resize(4 * n, INT_MIN);
        init(nums, 1, 1, n);

        vector<int> ans;
        for (int i = 1; i <= n - k + 1; i++) ans.push_back(getMax(i, i + k - 1, 1, 1, n));
        return ans;
    }
};
