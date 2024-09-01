class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        inStack.push(x);
    }
    
    int pop() {
        CheckAndReadyOutStack();

        const int front = outStack.top();
        outStack.pop();
        return front;
    }
    
    int peek() {
        CheckAndReadyOutStack();
        return outStack.top();
    }
    
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
private:
    void CheckAndReadyOutStack()
    {
        if (outStack.empty() == false)
        {
            return;
        }

        while(inStack.empty() == false)
        {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }

    std::stack<int> inStack;
    std::stack<int> outStack;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */