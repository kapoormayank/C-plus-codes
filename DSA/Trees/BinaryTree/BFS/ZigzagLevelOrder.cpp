// Zigzag Level Order Traversal of a Binary Tree Algorithm Implementation In C++
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
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

// Method to traverse the zigzag level order(DFS)
void zigzagLevelOrder(Node* root){
    if(root == nullptr){
        return;
    }
    queue<Node*> q;
    // Push Operation
    q.push(root);
    q.push(nullptr);
    vector<vector<int>> list;
    vector<int> level;
    while (!q.empty()) {
        // Store the queue first element
        Node* currentNode=q.front();
        // Remove the queue first element
        q.pop();
        if(currentNode == nullptr){
            list.push_back(level);
            level.clear();
            // Check queue is empty or not
            if(q.empty()){
                break;
            }
            q.push(nullptr);
        } else{
            level.push_back(currentNode->data);
            if(currentNode->left != nullptr){
                q.push(currentNode->left);
            }
            if(currentNode->right != nullptr){
                q.push(currentNode->right);
            }
        }
    }
    for(int i=0;i<list.size();i++){
        if(i%2 == 1){
            reverse(list[i].begin(),list[i].end());
        }
        for(int j=0;j<list[i].size();j++){
            cout<<list[i][j]<<" ";
        }
        cout<<"\n";
    }
}

// Main function
int main(){
    int nodes[]={4,2,1,-1,-1,3,-1,-1,6,5,-1,-1,7,-1,-1};
    BinaryTree bt;
    int k=sizeof(nodes)/sizeof(nodes[0]);
    Node* root=bt.buildTree(nodes,k);
    cout<<"Root of Binary Tree(BT) is : "<<root->data<<"\n";
    cout<<"Zigzag Level Order Traversal of Binary Tree(BT)\n";
    zigzagLevelOrder(root);
    return 0;
}

