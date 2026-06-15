class myStack {
  public:
  
    vector<int> arr;
    int capacity=0;
  
    myStack(int n) {
        // Define Data Structures
        capacity = n;
    }

    bool isEmpty() {
        // check if the stack is empty
        if(arr.size()==0) return true;
        return false;
    }

    bool isFull() {
        // check if the stack is full
        if(arr.size()==capacity) return true;
        return false;
    }

    void push(int x) {
        // inserts x at the top of the stack
        arr.push_back(x);
    }

    void pop() {
        // removes an element from the top of the stack
        if(arr.size()==0) return;
        arr.pop_back();
    }

    int peek() {
        // Returns the top element of the stack
        if(arr.size()==0) return -1;
        return arr.back();
    }
};