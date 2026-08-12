class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        stack<pair<int, int>> S;
        vector<int> ret(temps.size(), 0);
        for (int i = 0; i < temps.size(); i++) {
            while (!S.empty() && S.top().first < temps[i]) {
                ret[S.top().second] = i - S.top().second;
                S.pop();
            }
            S.push({temps[i], i});
        }
        return ret;
    }
};
