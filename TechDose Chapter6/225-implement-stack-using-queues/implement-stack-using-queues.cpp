class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        while(!input.empty()){
            output.push(input.front());
            input.pop();
        }
        input.push(x);
        while(!output.empty()){
            input.push(output.front());
            output.pop();
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
    queue<int>output;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
