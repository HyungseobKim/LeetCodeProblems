class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        if (topAtFront)
        {
            const int topElement = q.front();
            q.pop();
            q.push(topElement);

            topAtFront = false;
        }

        q.push(x);
    }
    
    int pop() {
        const int topElement = top();
        q.pop();

        topAtFront = false;
        return topElement;
    }
    
    int top() {
        if (topAtFront == false)
        {
            moveTopToFront();
        }
        
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }

private:
    void moveTopToFront()
    {
        const int size = q.size();

        for (int i = 1; i < size; ++i)
        {
            const int topElement = q.front();
            q.pop();
            q.push(topElement);
        }

        topAtFront = true;
    }

    std::queue<int> q;
    bool topAtFront = false;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
 
class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        topElement = x;
    }
    
    int pop() {
        const int numShift = q.size() - 2;
        for (int i = 0; i < numShift; ++i)
        {
            const int element = q.front();
            q.pop();
            q.push(element);
        }

        topElement = q.front();
        q.pop();
        q.push(topElement);

        const int element = q.front();
        q.pop();
        return element;
    }
    
    int top() {
        return topElement;
    }
    
    bool empty() {
        return q.empty();
    }
private:
    std::queue<int> q;
    int topElement;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */