#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Qnode{
    public:
    int data;
    Qnode *next;
    Qnode(int val){
        data=val;
        next=NULL;
    }
};
class Queue{
    Qnode *head,*rear;
    public:
    Queue(){
        head=rear=NULL;
    }

    void enqueue(int val){
        Qnode *nn=new Qnode(val);
        if(head==NULL){
            head=rear=nn;
            return;
        }
        rear->next=nn;
        rear=nn;
    }

    void dequeue(){
        if(head==NULL){
            cout<<"Queue is empty"<<endl;
            return ;
        }
        Qnode *temp=head;
        head=head->next;
        if(head==NULL){
            rear=NULL;
        }
        delete temp;
    }

    int front(){
        if(head==NULL){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return head->data;
    }
    bool isEmpty(){
        return head==NULL;
    }
    void display(){
        Qnode *temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
int main(){
    Queue q;
    q.dequeue();
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    cout<<q.front();
}