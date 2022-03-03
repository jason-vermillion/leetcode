// https://leetcode.com/problems/maximum-width-of-binary-tree/
// 662. Maximum Width of Binary Tree
#define ll long long
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int result = INT_MIN;
        
        if (root == nullptr) {
            return 0;
        }
        
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        
        while(!q.empty()) {
            int sz = q.size();
            int x = q.front().second;
            int left, right;
            
            for(int i = 0; i < sz; ++i) {
                int index = q.front().second - x;
                TreeNode* node = q.front().first;
                q.pop();

                if(i == 0) {
                    left = index;
                }

                if(i == sz - 1) {
                    right = index;
                }

                if(node -> left != NULL){
                    q.push({node -> left, (ll )index * 2 + 1});
                }
                if(node->right!=NULL){
                    q.push({node -> right, (ll) index * 2 + 2});
                }
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};