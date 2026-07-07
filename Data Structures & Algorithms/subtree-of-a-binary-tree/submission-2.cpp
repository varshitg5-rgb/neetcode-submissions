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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL && subRoot==NULL){
            return true;
        }
        if(subRoot==NULL || root==NULL) return false;

        if(issame(root,subRoot)) return true;
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }

    bool issame(TreeNode* root, TreeNode* subRoot){
         if(root==NULL && subRoot==NULL){
            return true;
        }
        if(subRoot==NULL || root==NULL) return false;
        if(root->val==subRoot->val){
            return issame(root->left,subRoot->left) && issame(root->right,subRoot->right);
        }
        return false;
    }
};
