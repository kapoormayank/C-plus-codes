// Search Nodes from Binary Tree(BT) Algorithm Implementation In C++
#include<iostream>
#include<queue>
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
        Node* newNode =new Node(nodes[index]);
        // Recursive Function
        newNode->left=buildTree(nodes,k);
        newNode->right=buildTree(nodes,k);
        return newNode;
    }
};

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

// Method to search the node which exists in BT
bool SearchOfNodes(Node* root,int target){
    if(root == nullptr){
        return false;
    }
    if(root->data > target){
        return SearchOfNodes(root->left,target);
    }
    else if(root->data < target) {
        return SearchOfNodes(root->right,target);
    }
    return false;
}

// Main function
int main(){
    int nodes[]={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    int k=sizeof(nodes)/sizeof(nodes[0]);
    BinaryTree tree;
    Node* root=tree.buildTree(nodes,k);
    cout<<"Root of Binary Tree(BT) is: "<<root->data<<endl;
    cout<<"Print all nodes of Binary Tree(BT): ";
    print(root);
    int target=6;
    if(SearchOfNodes(root,target)){
        cout<<"\nTarget "<<target<<" node is exist in BST..."<<endl;
    }else {
        cout<<"\nTarget "<<target<<" node does n't exist in BST..."<<endl;
    }
    return 0;
}
