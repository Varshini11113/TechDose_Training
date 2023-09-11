class MyStack {
    queue<int>q;
    int t;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        t = x;
    }
    
    int pop() {
        int x;
        for(int i = 0; i<q.size()-1; i++){
            x = q.front();
            q.pop();
            q.push(x);
        }
        t = x;
        x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return t;
    }
    
    bool empty() {
        return q.empty();
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