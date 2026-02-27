// Searching In BST Algorithm Implementation In C++
#include<iostream>
using namespace std;
// Node class of Binary Search Tree(BST)
class Node {
    // Public Access Modifier
    public:
    int data;
    Node* left;
    Node* right;
    // Parameterized Constructor
    Node(int data) {
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
    }
};

// Function to insert the nodes in BST
Node* insert(Node* root, int val) {
    if(root == nullptr) {
        return new Node(val);
    }
    // Recursive Function
    if(root->data > val){
        // Left Subtree
        root->left=insert(root->left,val); 
    }
    else if(root->data < val){
        // Right Subtree
        root->right=insert(root->right,val); 
    }
    return root;
}

// Function to print all nodes of BST
void print(Node* root){
    if(root == nullptr) {
        return;
    }
    cout<<root->data<<" ";
    // Recursive Function
    print(root->left); // Left Subtree
    print(root->right); // Right Subtree
}

// Function to search the target node from BSt
bool search(Node* root,int target) {
    if(root == nullptr) {
        return false;
    }
    if(root->data == target) {
        return true;
    }
    // Recursive Function
    if(root->data > target) {
        return search(root->left,target); // Left Subtree
    }
    if(root->data < target) {
        return search(root->right,target); // Right Subtree
    }
    return false;
}

// Main function
int main() {
    int nums[]={50,30,80,25,20,70,75,110,100,90,65};
    Node* root=nullptr;
    for(int num:nums) {
        root=insert(root,num);
    }
    cout<<"Print all nodes of BST: ";
    print(root);
    int target=65;
    if(search(root,target)){
        cout<<"\nTarget "<<target<<" node is exist in BST..."<<endl;
    }else {
        cout<<"\nTarget "<<target<<" node does n't exist in BST..."<<endl;
    }
    return 0;
}
