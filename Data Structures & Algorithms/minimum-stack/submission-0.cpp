class MinStack {
public:
    MinStack()
    {
    }
    
    void push(int val)
    {
        if (myStack_.empty()) myStack_.push({val, val});
        else if (myStack_.top().second > val)
        {
            myStack_.push({val, val});
        }
        else
        {
            myStack_.push({val, myStack_.top().second});
        }
    }
    
    void pop()
    {
        myStack_.pop();
    }
    
    int top()
    {
        return myStack_.top().first;
    }
    
    int getMin()
    {
        return myStack_.top().second;
    }
private:
    stack<std::pair<int, int>> myStack_;
};
