/*
	Follow-up: Can you implement the queue such that each operation is amortized O(1) time complexity? In other words, performing n operations will take overall O(n) time even if one of those operations may take longer.
*/
class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        inStack.push(x);
    }
    
    int pop() {
        if (outStack.empty())
        {
            MoveAll(inStack, outStack);
        }

        const int top = outStack.top();
        outStack.pop();

        return top;
    }
    
    int peek() {
        if (outStack.empty())
        {
            MoveAll(inStack, outStack);
        }

        return outStack.top();
    }
    
    bool empty() {
        return inStack.empty() && outStack.empty();
    }

private:
    void MoveAll(std::stack<int>& stackToClear, std::stack<int>& stackToFill)
    {
        const int size = stackToClear.size();

        for (int i = 0; i < size; ++i)
        {
            const int top = stackToClear.top();
            stackToClear.pop();

            stackToFill.push(top);
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