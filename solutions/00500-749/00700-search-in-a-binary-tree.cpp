// https://leetcode.com/problems/search-in-a-binary-search-tree/
// 700. Search in a Binary Search Tree
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
    TreeNode* searchBST(TreeNode* root, int val) {
        return search(root, val);
    }
    
    TreeNode* search(TreeNode* root, int val) {
        TreeNode* res;
        
        if (root == nullptr || root -> val == val) return root;
        
        if (root -> val > val) {
            res = search(root -> left, val);
        }
        else {
            res = search(root -> right, val);
        }
        
        return res;
    }
};