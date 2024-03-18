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