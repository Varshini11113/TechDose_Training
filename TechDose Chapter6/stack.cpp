#include <iostream>
#include <vector>

using namespace std;

class Stack {
private:
    vector<int> elements;

public:
    // Check if the stack is empty
    bool isEmpty() {
        return elements.empty();
    }

    // Push an element onto the stack
    void push(int value) {
        elements.push_back(value);
    }

    // Remove and return the top element of the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1; // Error value
        }
        int value = elements.back();
        elements.pop_back();
        return value;
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1; // Error value
        }
        return elements.back();
    }
};

int main() {
    Stack myStack;

    // Pushing elements onto the stack
    myStack.push(5);
    myStack.push(10);
    myStack.push(15);

    // Accessing the top element of the stack
    cout << "Top element of the stack: " << myStack.top() << endl;

    // Popping elements from the stack
    cout << "Popping elements from the stack: ";
    while (!myStack.isEmpty()) {
        cout << myStack.pop() << " ";
    }
    cout << endl;

    return 0;
}

//2nd method
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
//stack Implementation

class Stack{
    public:
    vector<int>st;
    int size=-1;
    Stack(int n){st.resize(n);}
    
    void push(int val){
        if(st.size()-1==size){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        size++;
        st[size]=val;
    }

    void pop(){
        if(size==-1){
            cout<<"Stack Underflow"<<endl;
            return ;
        }
        size--;
    }

    int top(){
        if(size==-1)return -1;
        return st[size];
    }

    bool isEmpty(){
        return size==-1;
    }

    int len(){
        return size+1;
    }
    void display(){
        for(int i=0;i<=size;i++){
            cout<<st[i]<<" ";
        }
        cout<<endl;
    }
};


int main(){
    class Stack st1(4);
    st1.push(10);
    cout<<st1.top();
    cout<<endl<<st1.len();
}
