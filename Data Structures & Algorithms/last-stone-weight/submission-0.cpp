class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> Q(stones.begin(), stones.end());
        while (Q.size() >= 2) {
            int x = Q.top(); Q.pop();
            int y = Q.top(); Q.pop();
            if (x != y) Q.push(abs(x - y));
        }
        return Q.empty() ? 0 : Q.top();
    }
};
