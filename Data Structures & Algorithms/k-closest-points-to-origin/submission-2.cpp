class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> Q;
        for (auto &p : points) {
            int dist = p[0]*p[0] + p[1]*p[1];
            Q.push({dist, {p[0], p[1]}});
            if (Q.size() > k) Q.pop();
        }
        vector<vector<int>> ret;
        while (!Q.empty()) {
            auto [_, p] = Q.top(); Q.pop();
            ret.push_back({p.first, p.second});
        }
        return ret;
    }
};
