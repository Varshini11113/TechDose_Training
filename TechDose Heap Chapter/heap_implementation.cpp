// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// void swap(int *a, int *b){
//     int temp = *b;
//     *b = *a;
//     *a = temp;
// }

//Heapification algorithm

void heapify(vector<int>&heap, int i){
    int size = heap.size();
    int lar = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < size && heap[left] > heap[lar]){
        lar = left;
    }
    if(right < size && heap[right] > heap[lar]){
        lar = right;
    }
    if(lar != i){
        swap(heap[lar], heap[i]);
        heapify(heap, lar);
    }
}

void push(vector<int>&heap, int num){
    int size = heap.size();
    if(size == 0){
        heap.push_back(num);
    }
    else{
        heap.push_back(num);
        for(int i = size/2 - 1; i>=0; i--){
            heapify(heap, i);
        }
    }
}

void printHeap(vector<int>&heap){
    for(int i = 0; i<heap.size(); i++){
        cout<<heap[i]<<" ";
    }
}

int main() {
    // Write C++ code here
    // std::cout << "Hello world!";
    vector<int>heap;
    push(heap, 1);
    push(heap, 9);
    push(heap, 12);
    push(heap, 6);
    push(heap, 5);
    push(heap, 7);
    
    cout<<"The heap DS formed is : "<<endl;
    printHeap(heap);
    return 0;
}