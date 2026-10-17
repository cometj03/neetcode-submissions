class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> Q;

    KthLargest(int k, vector<int>& nums) : k(k), Q(nums.begin(), nums.end()) {
        while (Q.size() > k) {
            Q.pop();
        }
    }
    
    int add(int val) {
        Q.push(val);
        if (Q.size() > k) Q.pop();
        return Q.top();
    }
};
