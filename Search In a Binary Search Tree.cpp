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
    TreeNode *ans=NULL;
    int v;
    void solve(TreeNode* root)
    {
        if(root==NULL)
            return;
        if(root->val==v)
        {
            ans=root;
            return;
        }
        if(root->val<v)
        {
            solve(root->right);
            return;
        }
        if(root->val>v)
        {
            solve(root->left);
            return;
        }
        
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL)
            return root;
        v=val;
        solve(root);
        return ans;
    }
};