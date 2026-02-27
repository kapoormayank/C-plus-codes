// Right Side View Of BST Algorithm Implementatio In C++

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
void rightSide_View(Node* root) {
    if(root == nullptr) {
        return;
    }
    // Recursive Function
    cout<<root->data<<" ";
    rightSide_View(root->right); // Right Subtree
}


// Main function
int main() {
    int nums[]={50,30,80,20,70,75,100,110,90,25,65};
    Node* root=nullptr;
    for(int num:nums) {
        root=insert(root,num);
    }
    cout<<"Print all nodes of BST: ";
    print(root);
    cout<<"\nRight Side View Of Binary Search Tree(BST): ";
    rightSide_View(root);
    return 0;
}
