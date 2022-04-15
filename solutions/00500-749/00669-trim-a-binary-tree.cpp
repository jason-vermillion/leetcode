// https://leetcode.com/problems/trim-a-binary-search-tree/
// 669. Trim a Binary Search Tree
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return nullptr;
        }
        
        if (low <= root -> val && root -> val <= high) {
            root -> left = trimBST(root -> left, low, high);
            root -> right = trimBST(root -> right, low, high);
        }
        else if (root -> val < low) {
            root = trimBST(root -> right, low, high);
        }
        else if (root -> val > high) {
            root = trimBST(root -> left, low, high);
        }
        
        return root;
        
    }
};