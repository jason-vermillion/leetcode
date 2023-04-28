// https://leetcode.com/problems/binary-tree-inorder-traversal/description/
// 94. Binary Tree Inorder Traversal
// 00094-binary-tree-inorder-traversal.cpp

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
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        traverse(root, result);
        return result;
    }

    void traverse(TreeNode *node, vector<int> &result)
    {
        if (node == nullptr)
        {
            return;
        }

        traverse(node->left, result);
        result.push_back(node->val);
        traverse(node->right, result);
    }
};