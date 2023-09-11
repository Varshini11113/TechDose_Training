class MyQueue {
    // stack<int> input, output;
public:

    void push(int x) {
        input.push(x);
    }

    int pop(void) {
        peek();
        const int val = output.top();
        output.pop();
        return val;
    }

    int peek(void) {
        if (output.empty())
            while (input.size())
                output.push(input.top()), input.pop();
        return output.top();
    }

    bool empty(void) {
        return input.empty() && output.empty();
    }
private:
    stack<int>input;
    stack<int>output;
};