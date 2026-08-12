class MinStack {
private:
    stack<int> S, M;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (M.empty() || M.top() >= val) M.push(val);
        S.push(val);
    }
    
    void pop() {
        if (S.top() == M.top()) M.pop();
        S.pop();
    }
    
    int top() {
        return S.top();
    }
    
    int getMin() {
        return M.top();
    }
};
