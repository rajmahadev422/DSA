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
    int ans = 0;
    pair<int, int> dfs(TreeNode* root) {
        if(!root) return make_pair(0,0);

        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);

        if((left.first + right.first + root->val) / (left.second + right.second + 1) == root->val) ans++;
        return make_pair(left.first + right.first + root->val, left.second + right.second + 1);

    }
    int averageOfSubtree(TreeNode* root) {
        pair<int, int> p = dfs(root);
        
        return ans;
    }
};