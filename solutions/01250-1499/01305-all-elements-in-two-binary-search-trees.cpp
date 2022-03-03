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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> allElements;
        vector<int> list1;
        vector<int> list2;
        
        list1 = getInorderedList(root1);
        list2 = getInorderedList(root2);
        allElements = mergeLists(&list1, &list2);
        
        return allElements;
    }

vector<int> mergeLists(vector<int>* list1, vector<int>* list2) {
    vector<int> combined;
    int i = 0, j = 0;
    
    while(i < list1 -> size() || j < list2 -> size()) {
        if (i < list1 -> size() && j < list2 -> size()) {
            if (list1 -> at(i) < list2 -> at(j)) {
                combined.push_back(list1 -> at(i));
                i++;
            }
            else {
                combined.push_back(list2 -> at(j));
                j++;
            }
        }
        else if (i < list1 -> size()) {
            combined.push_back(list1 -> at(i));
            i++;      
        }
        else {
            combined.push_back(list2 -> at(j));
            j++;             
        }
    }
    
    return combined;
}
    
vector<int> getInorderedList(TreeNode* root) {
    vector<int> list;
    
    inorder(root, &list);
    
    return list;
}
    
void inorder(TreeNode* root, vector<int>* list) {
    if (root != NULL) {
        inorder(root -> left, list);
        list -> push_back(root -> val);
        inorder(root -> right, list);
    }
}
};