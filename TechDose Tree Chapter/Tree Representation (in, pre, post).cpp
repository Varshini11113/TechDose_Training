// Online C++ compiler to run C++ program online
// Online C++ compiler to run C++ program online
// #include <iostream>
// using namespace std;
// struct node {
//     int data;
//     struct node *left;
//     struct node *right;
// };
// node* nn(int val){
//     struct node *temp = new node;
//     temp->data = val;
//     temp->left = temp->right = NULL;
//     return temp;
// }

// void inorder(node *root){
//     if(root == NULL) return;
//     inorder(root->left);
//     cout<<root->data<<" ";
//     inorder(root->right);
// }

// void preorder(node *root){
//     if(root == NULL) return;
//     cout<<root->data<<" ";
//     preorder(root->left);
//     preorder(root->right);
// }

// void postorder(node *root){
//     if(root == NULL) return;
//     postorder(root->left);
//     postorder(root->right);
//     cout<<root->data<<" ";
// }

// int main() {
//     // Write C++ code here
//     // std::cout << "Hello world!";
//     struct node *root = nn(1);
//     root->left = nn(3);
//     root->right = nn(5);
//     root->left->right = nn(11);
//     inorder(root);
//     cout<<"Inorder Traversal"<<"\n";
//     preorder(root);
//     cout<<"Preorder Traversal"<<"\n";
//     postorder(root);
//     cout<<"Postorder Traversal"<<"\n";
//     return 0;
// }

#include<iostream>
using namespace std;

// struct node{
//     int data;
//     struct node *left, *right;
// };

// node* nn(int val){
//     struct node *temp = new node;
//     temp->data = val;
//     temp->left = temp->right = NULL;
//     return temp;
// }

//TreeNode structure
struct node {
    int data;
    struct node *left, *right;
}

node* nn(int val){
    struct node *temp = new node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void inorder(node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(node *root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->rigth);
    cout<<root->data<<" ";
}

void preorder(node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    struct node *root = nn(1);
    root->left = nn(20);
    root->right = nn(30);
    root->left->right = nn(50);
    inorder(root);
    preorder(root);
    postorder(root);
    return 0;
}