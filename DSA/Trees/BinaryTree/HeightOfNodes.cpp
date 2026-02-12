// Height Of Node Algorithm Implementation In C++
#include<iostream>
using namespace std;

// Node class of Binary Tree(BT)
class Node{
    // Public Access Modifier And Data Members
    public:
    int data;
    // Pointer To Left And Right Child Of Node
    Node* left;
    Node* right;
    // Parameterized Constructor
    Node(int data){
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
    }
};

// class to find the root of Binary Tree(BT)
class BinaryTree{
    public:
    int index=-1;
    Node* buildTree(int nodes[]){
        index++;
        if(nodes[index] == -1){
            return nullptr;
        }
        // Creating New Node
        Node* newNode =new Node(nodes[index]);
        // Recursive Function
        newNode->left=buildTree(nodes); // for left child of Binary Tree(BT)
        newNode->right=buildTree(nodes); // for right child of Binary Tree(BT)
        return newNode;
    }
};

// Method to find the Height of Binary Tree(BT) 
int HeightOfNodes(Node* root){
    if(root == nullptr){
        return 0;
    }
    // Recursive function
    int leftHeight=HeightOfNodes(root->left);
    int rightHeight=HeightOfNodes(root->right);
    return max(leftHeight,rightHeight)+1;
}

// Main function
int main(){
    int nodes[]={2,4,8,-1,-1,9,10,-1,-1,11,-1,-1,3,6,-1,-1,7,-1,-1};
    BinaryTree* tree=new BinaryTree();
    Node* root=tree->buildTree(nodes);
    cout<<"Root of Binary Tree is: "<<root->data<<endl;
    HeightOfNodes(root);
    cout<<"Height Of Binary Tree is: "<<HeightOfNodes(root)<<endl;
    return 0;
}

