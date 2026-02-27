// Deleteing In BST Algorithm Implementation In C++
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

// Function to min value from BST
int minValue(Node* root) {
    int minv=root->data;
    while(root->left != nullptr) {
        minv=root->left->data;
        root=root->left;
    }
    return minv;
}

// Function to delete the target node from BSt
Node* deleteNode(Node* root,int target) {
    if(root == nullptr) {
        return nullptr;
    }
    // Recursive calls for left and right subtrees
    if(root->data > target) {
        // Left Subtree
        root->left = deleteNode(root->left,target); 
    }else if(root->data < target) {
        // Right Subtree
        root->right = deleteNode(root->right,target); 
    }else {
        if(root->left == nullptr) {
            return root->right;
        }else if(root->right == nullptr) {
            return root->left;
        }
        // Node with two children: Get the inorder successor (smallest in the right subtree)
        root->data = minValue(root->right);
        // Delete the inorder successor
        root->right = deleteNode(root->right, root->data);
    }
    return root;
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
    root=deleteNode(root,target);
    cout << "\nBST after deleting " << target << ": ";
    print(root);
    cout << endl;
    return 0;
}
