// Sum of Left Leaves in a Binary Tree Algorithm Implementation In C++
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
    Node* buildTree(int nodes[],int k){
        index++;
        if(index >= k || nodes[index] == -1){
            return nullptr;
        }
        // Create a new node with the current index value
        Node* newNode=new Node(nodes[index]);
        // Recursive calls to build the left and right subtrees
        newNode->left=buildTree(nodes,k);
        newNode->right=buildTree(nodes,k);
        return newNode;
    }
};

// Method to sum of left leaves in a binary tree
int sumOfLeftLeaves(Node* root){
    if(root == nullptr){
        return 0;
    }
    int sum=0;
    if(root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
    {
        sum+=root->left->data;
    }
    return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}

// Main function
int main(){
    int nodes[]={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    int k=sizeof(nodes)/sizeof(nodes[0]);
    BinaryTree tree;
    Node* root=tree.buildTree(nodes,k);
    cout<<"Root of the Binary Tree: "<<root->data<<endl;
    cout<<"Sum of Left Leaves: "<<sumOfLeftLeaves(root)<<endl;
    return 0;
}
