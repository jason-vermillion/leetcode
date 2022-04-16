// https://leetcode.com/problems/convert-bst-to-greater-tree/
// 538. Convert BST to Greater Tree
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
private:
    int total = 0;
public:
    void helper(TreeNode* root){
        if (root == nullptr) {
            return;
        }
        
        if (root -> right != nullptr) {
            helper(root -> right);
        }
        
        total = total + root -> val;
        root -> val = total;
        
        if (root -> left != nullptr) {
            helper(root -> left);
        }
    }
    
    TreeNode* convertBST(TreeNode* root) {
        helper(root);
        return root;
    }
};