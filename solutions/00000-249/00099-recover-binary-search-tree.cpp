// https://leetcode.com/problems/recover-binary-search-tree/
// 99. Recover Binary Search Tree
// Time complexity O(N)
// Space complexity O(1)
// BST, inorder traversal
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
    TreeNode *prev = nullptr, *a = nullptr, *b = nullptr;
public:
    void recoverTree(TreeNode* root) {
        // traverse the tree inorder from smallest to largest value and look
        // for the 2 places that are out of order.
        
        inorder(root);
        
        swap(a -> val, b -> val);
        
        return;
    }
    
    void inorder(TreeNode* curr) {
        if (curr == nullptr) return;
        
        inorder(curr -> left);
        
        if (prev != nullptr && prev -> val > curr -> val) {
            if (a == nullptr) {
                a = prev;
            }
            b = curr;
        }
        prev = curr;
        
        inorder(curr -> right);
    }
};