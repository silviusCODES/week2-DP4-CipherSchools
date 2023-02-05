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

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    static bool cmp(const pair<pair<int, int>, TreeNode *> &a,
                    const pair<pair<int, int>, TreeNode *> &b)
    {
        if (a.first == b.first)
            return (a.second->val < b.second->val);
        return a.first < b.first;
    }
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;
        queue<pair<pair<int, int>, TreeNode *>> q;
        q.push({{0, 0}, root});
        int l = 0;
        vector<pair<pair<int, int>, TreeNode *>> t;
        while (!q.empty())
        {
            auto it = q.front();
            int row = it.first.second;
            int col = it.first.first;
            t.push_back(it);
            q.pop();
            if (it.second->left)
                q.push({{col - 1, row + 1}, it.second->left});
            if (it.second->right)
                q.push({{col + 1, row + 1}, it.second->right});
        }
        sort(t.begin(), t.end(), cmp);
        vector<int> row;
        row.push_back(t[0].second->val);
        cout << t.size() << "\n";
        for (int i = 1; i < t.size(); i++)
        {
            if (t[i - 1].first.first == t[i].first.first)
            {
                row.push_back(t[i].second->val);
            }
            else
            {
                ans.push_back(row);
                row.clear();
                row.push_back(t[i].second->val);
            }
        }
        ans.push_back(row);

        return ans;
    }
};