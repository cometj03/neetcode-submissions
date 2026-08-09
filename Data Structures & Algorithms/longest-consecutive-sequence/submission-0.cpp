class Solution {
public:
    unordered_map<int, int> P;
    int Find(int v) {
        if (P[v] == v) return v;
        return P[v] = Find(P[v]);
    }
    void Union(int v, int u) {
        int x = Find(v), y = Find(u);
        P[x] = y;
    }
    int longestConsecutive(vector<int>& nums) {
        for (int n : nums) P[n] = n;
        for (int n : nums) {
            if (P.contains(n - 1)) {
                Union(n, n - 1);
            }
        }
        // for (auto [k, v] : P) cout << k << ", " << v << '\n';

        unordered_map<int, int> count;
        for (auto [n, _] : P) {
            int p = Find(n);
            count[p]++;
        }
        // cout << "count\n";
        // for (auto [k, v] : count) cout << k << ", " << v << '\n';
        int ans = 0;
        for (auto [_, cnt] : count) ans = max(ans, cnt);
        return ans;
    }
};
