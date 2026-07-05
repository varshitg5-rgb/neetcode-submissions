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
    int goodNodes(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,INT_MIN});
        int ans = 0;
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            int t = x.second;
            TreeNode* cur = x.first;
            if(cur->val>=t) ans++;

            if(cur->left!=NULL){
                q.push({cur->left,max(t,cur->val)});
            }
            if(cur->right!=NULL){
                q.push({cur->right,max(t,cur->val)});
            }
        }
        return ans;
    }
};
