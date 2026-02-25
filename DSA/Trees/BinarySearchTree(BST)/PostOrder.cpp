// Post-order Traversal Of BST Algorithm Implementation In Java
// Time Complexity: O(n)
// Space Complexity: O(h)

#include<iostream>
using namespace std;

// Node class of BST
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

// Function to insert a nodes of BST
Node* insert(Node* root,int val) {
    if(root == nullptr) {
        return new Node(val);
    }
    // Recursive Function
    if(root->data > val) {
        // Left Subtree
        root->left=insert(root->left,val);
    }
    if(root->data < val) {
        // Right Subtree
        root->right=insert(root->right,val);
    }
    return root;
}

// Function to perform the post-order traversal
void postOrder(Node* root) {
    if(root == nullptr) {
        return;
    }
    // recursive function
    postOrder(root->left); // Left Subtree
    postOrder(root->right); // Right Subtree
    cout<<root->data<<" ";
}

// Main function
int main() {
    int values[]={5,3,6,2,4,7};
    Node* root=nullptr;
    for(int num:values) {
        root=insert(root,num);
    }
    cout<<"Post-Order Traversal: ";
    postOrder(root);
    return 0;
}

