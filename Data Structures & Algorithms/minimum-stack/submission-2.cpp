class MinStack {
    stack<int> st;
    stack<int> ord; 
public:
    MinStack() {
    }
    
    void push(int val) {
        if (ord.empty()) ord.push(val);
        else if (val <= ord.top()) ord.push(val);
        st.push(val);
    }
    
    void pop() {
        if (st.top() == ord.top()) ord.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return ord.top();
    }
};
