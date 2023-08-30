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


//clean code - push(), pop(), heapifyUp, heapifyDown, maxHeap desc..

//Max_Heap

#include <iostream>
#include <vector>

class MaxHeap {
private:
    std::vector<int> heap;
    void heapifyUp(int index) {
        int parentIndex = index / 2;
        while (index > 1 && heap[index] > heap[parentIndex]) {
            std::swap(heap[index], heap[parentIndex]);
            index = parentIndex;
            parentIndex = index / 2;
        }
    }

    void heapifyDown(int index) {
        int n = heap.size() - 1;
        while (2 * index <= n) {
            int leftChildIndex = 2 * index;
            int rightChildIndex = 2 * index + 1;
            int largestIndex = index;

            if (leftChildIndex <= n && heap[leftChildIndex] > heap[largestIndex]) {
                largestIndex = leftChildIndex;
            }
            if (rightChildIndex <= n && heap[rightChildIndex] > heap[largestIndex]) {
                largestIndex = rightChildIndex;
            }

            if (largestIndex != index) {
                std::swap(heap[index], heap[largestIndex]);
                index = largestIndex;
            } else {
                break;
            }
        }
    }

public:
    void push(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int pop() {
        if (heap.size() <= 1) {
            return -1;  // Heap is empty
        }
        int root = heap[1];
        // std :: cout << root << " "; 
        heap[1] = heap.back();
        heap.pop_back();
        heapifyDown(1);
        return root;
    }

    void printDescendingOrder() {
        while (heap.size() > 1) {
            std::cout << pop() << " ";
        }
        std::cout << std::endl;
    }

    //builtheap algo
    void builtHeap(vector<int>&arr){
        int n = arr.size() - 1;//1 indexed
        for(int i=n/2 ;i>=1;--i ){
            heapifyDown(arr, i);
        }
    }

    //increase_key algo
    void increase_key(vector<int>&arr, int i, int key){
        if(key < arr[i]){
            cout << "Violates the rule\n";
            return false;
        }
        arr[i] = key;
        while(i > 1 && arr[i] > arr[i/2]){
            swap(arr[i], arr[i/2]);
            i /= 2;
        }
    }

    //decrease_key algo
    void decrease_key(vector<int>&arr, int i, int key){
        if(key > arr[i]){
            cout<<"Violate the rule\n";
            return false;
        }
        arr[i] = key;
        heapifyDown(arr, i);
    }
};

int main() {
    MaxHeap maxHeap;
    std::vector<int> elements = {5, 12, 3, 15, 10, 17};
    maxHeap.push(0);
    for (int element : elements) {
        maxHeap.push(element);
    }

    std::cout << "Elements in descending order:" << std::endl;
    maxHeap.printDescendingOrder();


    //Built heap algorithm
    vector<int>arr(n+1);
    cout<<"Getting the elements\n";
    for(int i = 1; i<=n; i++){
        cin >> arr[i];
    }
    builtHeap(arr);

    //increase_key algorithm --> increassing the key value so that it moves upwards.
    //boundary condition --> key should be grater than curr ele, else return false
    int key, index;
    cin >> key >> index;
    increase_key(arr, index, key);

    return 0;
}

//clean code for min_heap only the condtion changes [(x < left) && (x < right)];
//push(), pop(), asc, heapifyUp, heapifyDown

#include <iostream>
#include <vector>

class MinHeap {
private:
    std::vector<int> heap;

    void heapifyUp(int index) {
        int parentIndex = index / 2;
        while (index > 1 && heap[index] < heap[parentIndex]) {
            std::swap(heap[index], heap[parentIndex]);
            index = parentIndex;
            parentIndex = index / 2;
        }
    }

    void heapifyDown(int index) {
        int n = heap.size() - 1;
        while (2 * index <= n) {
            int leftChildIndex = 2 * index;
            int rightChildIndex = 2 * index + 1;
            int smallestIndex = index;

            if (leftChildIndex <= n && heap[leftChildIndex] < heap[smallestIndex]) {
                smallestIndex = leftChildIndex;
            }
            if (rightChildIndex <= n && heap[rightChildIndex] < heap[smallestIndex]) {
                smallestIndex = rightChildIndex;
            }

            if (smallestIndex != index) {
                std::swap(heap[index], heap[smallestIndex]);
                index = smallestIndex;
            } else {
                break;
            }
        }
    }

public:
    void push(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int pop() {
        if (heap.size() <= 1) {
            return -1;  // Heap is empty
        }
        int root = heap[1];
        heap[1] = heap.back();
        heap.pop_back();
        heapifyDown(1);
        return root;
    }

    void printAscendingOrder() {
        while (heap.size() > 1) {
            std::cout << pop() << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MinHeap minHeap;
    std::vector<int> elements = {5, 12, 3, 15, 10, 17};
    for (int element : elements) {
        minHeap.push(element);
    }

    std::cout << "Elements in ascending order:" << std::endl;
    minHeap.printAscendingOrder();

    return 0;
}

