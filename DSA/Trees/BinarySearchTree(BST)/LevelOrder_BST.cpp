// Level Order Traversal Algorithm Implementation In C++
#include<iostream>
#include <queue>
using namespace std;
// Node class of Binary Search Tree(BST)
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

// Function to insert the nodes of Binary Search Tree(BST)
Node* insert(Node* root,int val) {
    if(root == nullptr) {
        return new Node(val);
    }
    // Recrsive calls of Left or Right Subtree
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

// Function to display the Binary Search Tree(BST)
void display(Node* root) {
    if(root == nullptr) {
        return;
    }
    // Recursive calls to left and right subtree
    cout<<root->data<<" ";
    display(root->left); // Left Subtree
    display(root->right); // Right Subtree
}

// Method to traverse the level order(DFS)
void levelOrder(Node* root){
    if(root == nullptr){
        return;
    }
    queue<Node*> q;
    // Push Operation
    q.push(root);
    q.push(nullptr);
    while (!q.empty()) {
        // Store the queue first element
        Node* currentNode=q.front();
        // Remove the queue first element
        q.pop();
        if(currentNode == nullptr){
            cout<<"\n";
            // Check queue is empty or not
            if(!q.empty()){
                q.push(nullptr);
            }
        }else{
            cout<<currentNode->data<<" ";
            if(currentNode->left != nullptr){
                q.push(currentNode->left);
            }
            if(currentNode->right != nullptr){
                q.push(currentNode->right);
            }
        }
    }    
}

// Main Function
int main() {
    int values[]={5,3,6,2,4,7};
    Node* root=nullptr;
    for(int num:values) {
        root=insert(root,num);
    }
    cout<<"Print Binary Search Tree(BST): ";
    display(root);
    cout << "\nLevel Order Traversal:\n";
    levelOrder(root);
    return 0;
}

