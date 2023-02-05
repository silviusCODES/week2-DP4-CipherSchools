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
class Solution
{
public:
    TreeNode *fun(vector<int> &in, vector<int> &post, int InStart, int InEnd, int PostStart, int PostEnd)
    {
        if (InStart > InEnd || PostStart > PostEnd)
            return NULL; // base case for recursion
        int rootData = post[PostEnd];
        int i = 0;
        for (; i < in.size(); i++)
            if (in[i] == rootData)
                break;

        int leftInStart = InStart;
        int lefInEnd = i - 1;
        int leftPostStart = PostStart;
        int leftPostEnd = leftPostStart + lefInEnd - leftInStart;

        int rightInStart = i + 1;
        int rightInEnd = InEnd;
        int rightPostStart = leftPostEnd + 1;
        int rightPostEnd = PostEnd - 1;

        TreeNode *root = new TreeNode(rootData);

        root->left = fun(in, post, leftInStart, lefInEnd, leftPostStart, leftPostEnd);
        root->right = fun(in, post, rightInStart, rightInEnd, rightPostStart, rightPostEnd);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        return fun(inorder, postorder, 0, n - 1, 0, n - 1);
    }
};