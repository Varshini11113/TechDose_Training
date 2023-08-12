class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        input.push(x);
        for(int i = 0; i<input.size()-1; i++){
            input.push(input.front());
            input.pop();
        }
    }
    
    int pop() {
        int x = input.front();
        input.pop();
        return x;
    }
    
    int top() {
        return input.front();
    }
    
    bool empty() {
        if(!input.empty()) return false;
        return true;
    }
private:
    queue<int>input;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */