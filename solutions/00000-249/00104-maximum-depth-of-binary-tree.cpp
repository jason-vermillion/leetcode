// https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Time complexity O(2^N)
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
    int maxDepth(TreeNode* root) {
        int depth = 0;
        
        depth = getDepth(root, 0);
        
        return depth;
    }
private:
    int getDepth(TreeNode* node, int currDepth) {
        if (node == nullptr) {
            return currDepth;
        }
        
        return max(getDepth(node -> left, currDepth + 1), getDepth(node -> right, currDepth + 1));
    }
};