// Sum of Leafs in a Binary Tree Algorithm Implementation In C++
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
    Node(int data){
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
    }
};

// Class to find the root of Binary Tree(BT)
class BinaryTree{
    public:
    int index=-1;
    Node* buildTree(int nodes[] ,int k){
        index++;
        if(index >= k || nodes[index] == -1){
            return nullptr;
        }
        // Create a new node with the current index value
        Node* newNode =new Node(nodes[index]);
        // Recursive Function
        newNode->left=buildTree(nodes,k);
        newNode->right=buildTree(nodes,k);
        return newNode;
    }
};
// Method to find the sum of leafs in a binary tree
int sumOfLeafs(Node* root){
    if(root == nullptr){
        return 0;
    }
    // If the current node is a leaf node, return its value
    if(root->left == nullptr && root->right == nullptr){
        return root->data;
    }
    // Recursive Function
    return sumOfLeafs(root->left) + sumOfLeafs(root->right);
}

// Main function
int main(){
    int nodes[]={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    int k=sizeof(nodes)/sizeof(nodes[0]);
    BinaryTree bt;
    Node* root=bt.buildTree(nodes,k);
    cout<<"Root of the Binary Tree: "<<root->data<<endl;
    cout<<"Sum of leaf nodes: "<<sumOfLeafs(root)<<endl;
    return 0;
}
