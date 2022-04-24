// https://leetcode.com/problems/increasing-order-search-tree/
// 897. Increasing Order Search Tree
// binary search tree, BST, inorder traversal
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* tail;
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode();
        
        tail = dummy;
        inorder(root);
        
        return dummy -> right;
    }
    
    // inorder tree traversal
    void inorder(TreeNode* curr) {
        if (curr == nullptr) {
            return;
        }
        
        inorder(curr -> left);
        
        tail -> right = new TreeNode(curr -> val);
        tail = tail -> right;
        
        inorder(curr -> right);
        
        return;
        
    }
};