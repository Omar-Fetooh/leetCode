class myQueue {

  public:
    vector<int> arr;
    int front=0;
    int rear =-1;
    int currentLen =0;
    int maxiCap = 0;
  
    myQueue(int n) {
        // Define Data Structures
        maxiCap=n;
    }

    bool isEmpty() {
        // check if the queue is empty
        return currentLen ==0;
    }

    bool isFull() {
        // check if the queue is full
        return currentLen == maxiCap;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        arr.push_back(x);
        ++currentLen;
        ++rear;
    }

    void dequeue() {
        // Removes the front element of the queue.
        if(isEmpty()) return ;
        --currentLen;
        ++front;
    }

    int getFront() {
        // Returns the front element of the queue.
        if(isEmpty()) return -1;
        return arr[front];
    }

    int getRear() {
        // Return the last element of queue  
        if(isEmpty()) return -1;
        return arr[rear];
    }
};