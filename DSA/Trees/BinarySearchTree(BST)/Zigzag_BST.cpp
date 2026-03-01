// Zigzag Level Order Traversal Algorithm Implementation In C++
#include<iostream>
#include<queue>
using namespace std;
// Node class of Binary Search Tree(BST)
class Node {
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

// Function to insert the nodes in Binary Search Tree(BST)
Node* insert(Node* root,int val) {
    if(root == nullptr) {
        return new Node(val);
    }
    // Recursion calls of Left and Right Subtree
    if(root->data > val){
        // Left Subtree
        root->left=insert(root->left,val);
    }
    if(root->data < val){
        // Right Subtree
        root->right=insert(root->right,val);
    }
    return root;
}

// Function to display the nodes of Binary Search Tree(BST)
void display(Node* root) {
    if(root == nullptr){
        return;
    }
    cout<<root->data<<" ";
    // Recursive calls of Left ,right Subtree
    display(root->left); // Left Subtree
    display(root->right); // Right Subtree
}

// Zigzag Level Order Traversal
void zigzagLevelOrder(Node* root) {
    if(root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    bool leftToRight = true; // flag to alternate direction
    while(!q.empty()) {
        int levelSize = q.size();
        vector<int> level(levelSize);
        for(int i = 0; i < levelSize; i++) {
            Node* curr = q.front();
            q.pop();
            // insert in vector based on direction
            int index = leftToRight ? i : (levelSize - 1 - i);
            level[index] = curr->data;

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        // Print current level
        for(int val : level) cout << val << " ";
        cout << "\n";
        // Toggle direction
        leftToRight = !leftToRight;
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
    cout << "\nZigzag Level Order Traversal:\n";
    zigzagLevelOrder(root);
    return 0;
}

