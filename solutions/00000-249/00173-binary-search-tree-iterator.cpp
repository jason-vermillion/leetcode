// https://leetcode.com/problems/binary-search-tree-iterator/
// 173. Binary Search Tree Iterator
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
class BSTIterator {
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        addLeft(root);
    }
    
    int next() {
        TreeNode* top;
        if (st.empty()) return -1;
        
        top = st.top();
        st.pop();
        if (top -> right != nullptr) {
            addLeft(top -> right);
        }
        return top -> val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    
    void addLeft(TreeNode* root) {
        while(root != nullptr) {
            st.push(root);
            root = root -> left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */