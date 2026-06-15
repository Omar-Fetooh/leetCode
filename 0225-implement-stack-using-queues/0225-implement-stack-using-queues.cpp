class MyStack {
public:
    queue<int> q;
    queue<int> st;
    MyStack() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        while(st.size()!=1){
            q.push(st.front());
            st.pop();
        }
        int res = st.front();
        st.pop();
        while(q.size()){
            st.push(q.front());
            q.pop();
        }
        return res;
    }
    
    int top() {
        return st.back();
    }
    
    bool empty() {
        return st.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */