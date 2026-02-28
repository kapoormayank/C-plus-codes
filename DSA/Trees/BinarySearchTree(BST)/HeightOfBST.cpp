// Height Of BST Algorithm Implementation In C++
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

// Function to perform the pre-order traversal
void print(Node* root) {
    if(root == nullptr) {
        return;
    }
    // recursive function
    cout<<root->data<<" ";
    print(root->left); // Left Subtree
    print(root->right); // Right Subtree
}

// Function to count the nodes of BST
int heightNode(Node* root) {
    if(root == nullptr) {
        return 0;
    }
    // recursive function
    int leftheight=heightNode(root->left); // Left Subtree
    int rightheight=heightNode(root->right); // Right Subtree
    return max(leftheight,rightheight)+1;
}

// Main function
int main() {
    int values[]={5,3,6,2,4,7};
    Node* root=nullptr;
    for(int num:values) {
        root=insert(root,num);
    }
    cout<<"Print Binary Search Tree(BST): ";
    print(root);
    cout<<"\nHeight of Binary Search Tree(BST): "<<heightNode(root)<<endl;
    return 0;
}

