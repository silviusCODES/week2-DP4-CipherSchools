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

    void BackTrack(TreeNode* root,string s,vector<string> &v)
    {
        if(root->left==NULL && root->right==NULL)
        {
            s=s+to_string(root->val);
            v.push_back(s);
            return ;
        }
        s=s+to_string(root->val)+"->";
        if(root->left!=NULL)
        {
            BackTrack(root->left,s,v);
        }
        if(root->right!=NULL)
        {
            BackTrack(root->right,s,v);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        BackTrack(root,"",v);
        return v;
    }
};