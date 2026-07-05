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
    bool isValidBST(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{INT_MIN,INT_MAX}});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* cur = p.first;
            int l = p.second.first;
            int r = p.second.second;
            if(cur->val<=l || cur->val>=r) return false;
            if(cur->left!=NULL){
                q.push({cur->left,{l,cur->val}});
            }
            if(cur->right!=NULL){
                q.push({cur->right,{cur->val,r}});
            }
        }
        return true;
    }
};
