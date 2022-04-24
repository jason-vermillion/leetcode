// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// 230. Kth Smallest Element in a BST
// Time complexity O(N)
// Space complexity O(1)
// recursion, inorder tree traversal
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
    int i = 1;
    int kVal = -1;
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return kVal;
    }
    
    void inorder(TreeNode* root, int k) {
        if (root == nullptr) return;
        if (i > k) return;
        
        inorder(root -> left, k);
        
        //printf("val: %d, k: %d, i: %d\n", root -> val, k, i);
        if (i == k) {
            kVal = root -> val;
        }
        i++;
        
        inorder(root -> right, k);
        
        return;
    }
};