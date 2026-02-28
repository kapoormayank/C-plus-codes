// Deleting Node From Binary Tree(BT) Algorithm Implementation In C++
#include<iostream>
using namespace std;

// Node class of Binary Tree(BT)
class Node{
    // Public Access Modifier
    public:
    // Data Members
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

// Class to find the root of Binary Tree(BT)
class BinaryTree{
    public:
    int index=-1;
    Node* buildTree(int nums[],int k) {
        index++;
        if(index >= k || nums[index] == -1){
            return nullptr;
        }
        Node* newNode=new Node(nums[index]);
        // Recursive Function
        newNode->left=buildTree(nums,k);  // Left Subtree
        newNode->right=buildTree(nums,k); // Right Subtree
        return newNode;
    }
};

// Function to find the minimum value node from Binary Tree(BT)
int minValue(Node* root) {
    int minv=root->data;
    while(root->left != nullptr) {
        minv=root->left->data;
        root=root->left;
    }
    return minv;
}

// Function to delete the node from Binary Tree(BT)
Node* deleteNode(Node* root,int target) {
    if(root == nullptr) {
        return nullptr;
    }
    // Recursive calls for left and right subtrees
    if(root->data > target) {
        // Left Subtree
        root->left=deleteNode(root->left,target);
    }else if(root->data < target) {
        // Right Subtree
        root->right=deleteNode(root->right,target);
    }else {
        if(root->left == nullptr){
            return root->right;
        }else if(root->right == nullptr) {
            return root->left;
        }
         // Node with two children: Get the inorder successor (smallest in the right subtree)
        root->data=minValue(root->right);
        // Delete the inorder successor
        root->right = deleteNode(root->right, root->data);
    }
    return root;
}

// Method to print all nodes of BT
void print(Node* root) {
    if(root == nullptr) {
        return;
    }
    cout<<root->data<<" ";
    // Recrsive Function
    print(root->left); // Left Subtree
    print(root->right); // Right Subtree
}

// Main function
int main() {
    int nodes[]={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    int k=sizeof(nodes)/sizeof(nodes[0]);
    BinaryTree tree;
    Node* root=tree.buildTree(nodes,k);
    cout<<"Root of Binary Tree(BT) is: "<<root->data<<endl;
    cout<<"Print all nodes of Binary Tree(BT): ";
    print(root);
    int target=6;
    cout << "\nBT after deleting " << target << ": ";
    print(root);
    cout << endl;
    return 0;
}
