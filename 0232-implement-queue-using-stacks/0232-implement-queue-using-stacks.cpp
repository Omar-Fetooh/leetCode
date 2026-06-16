class MyQueue {
public:
    stack<int> q;
    stack<int> st;
    int front;
    MyQueue() {
        
    }
    
    void push(int x) {
        q.push(x);
        if(q.size()==1) front =x;
    }
    
    int pop() {
        while(q.size()>1) {
            st.push(q.top());
            q.pop();
        }
        int res= q.top();
        q.pop();
        while(st.size()){
            q.push(st.top());
            if(q.size()==1) front =st.top();
            st.pop();
        }
        return res;
    }
    
    int peek() {
        return front;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */