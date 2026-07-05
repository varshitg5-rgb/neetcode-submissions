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
    bool help(TreeNode* root, int &k, int &cur, int &ans){
        if(root==NULL) return false;
       

        bool a = help(root->left,k,cur,ans);
        if(a) return true;
        cur = cur+1;
         if(cur==k){
            ans = root->val;
            return true;
        }
        return help(root->right,k,cur,ans);

    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        int cur =0;
        help(root,k,cur,ans);
        return ans;
    }
};
