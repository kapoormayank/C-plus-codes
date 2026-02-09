// Leetcode Problme 94: Binary Tree Inorder Traversal

#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// BinaryTree builder (like your style)
class BinaryTree {
public:
    int index = -1;
    TreeNode* buildTree(int nodes[]) {
        index++;
        if (nodes[index] == -1) {
            return nullptr;
        }
        TreeNode* newNode = new TreeNode(nodes[index]);
        newNode->left = buildTree(nodes);
        newNode->right = buildTree(nodes);
        return newNode;
    }
};

// Solution class for LeetCode
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        traverseInorder(root, result);
        return result;
    }

private:
    void traverseInorder(TreeNode* node, vector<int>& result) {
        if (!node) return;
        traverseInorder(node->left, result);
        result.push_back(node->val);
        traverseInorder(node->right, result);
    }
};

// Main function to test
int main() {
    int nodes[] = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    BinaryTree treeBuilder;
    TreeNode* root = treeBuilder.buildTree(nodes);
    Solution sol;
    vector<int> inorder = sol.inorderTraversal(root);
    cout << "Inorder Traversal: ";
    for (int val : inorder) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
