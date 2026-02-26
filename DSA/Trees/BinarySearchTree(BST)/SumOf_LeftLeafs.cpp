// Sum of all left leafs nodes Algorithm Implementation In C++
#include<iostream>
using namespace std;

// Node class of BST
class Node{
    // Public Access Modifier
    public:
    // Data members
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
Node* insert(Node* root,int val) {
    if(root == nullptr) {
        return new Node(val);
    }
    // Recursion Function
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

// Function to print the Binary Search Tree(BST)
void print(Node* root) {
    if(root == nullptr) {
        return;
    }
    cout<<root->data<<" ";
    // Recursion function
    print(root->left); // Left Subtree
    print(root->right); // Right Subtree
}

// Function to sum of all nodes from Binary Search Tree(BST)
int sumofLeftNodes(Node* root) {
    if(root == nullptr) {
        return 0;
    }
    int sum=0;
    if(root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
        sum=sum+root->left->data;
    }
    return sum + sumofLeftNodes(root->left) + sumofLeftNodes(root->right);
}

// Main function
int main() {
    int values[]={50,30,80,25,20,70,75,110,100,90,65};
    Node* root=nullptr;
    for(int num:values) {
        root=insert(root,num);
    }
    cout<<"Print Binary Search Tree(BST): ";
    print(root);
    cout<<"\nSum of all left leafs nodes from Binary Search Tree(BST): "<<sumofLeftNodes(root)<<endl;
    return 0;
}


