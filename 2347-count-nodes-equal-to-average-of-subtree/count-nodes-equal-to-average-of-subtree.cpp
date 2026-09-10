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
        if(!root->left and !root->right) {
            ans++;
            return make_pair(root->val, 1);
        }

        if(!root->left) {
            pair<int, int> temp = dfs(root->right);
            if((temp.first + root->val) / (temp.second + 1) == root->val) ans++;
            return make_pair(temp.first + root->val, temp.second + 1);
        }
        else if(!root->right) {
            pair<int, int> temp = dfs(root->left);
            if((temp.first + root->val) / (temp.second + 1) == root->val) ans++;
            return make_pair(temp.first + root->val, temp.second + 1);
        }

        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);

        if((left.first + right.first + root->val) / (left.second + right.second + 1) == root->val) ans++;
        return make_pair(left.first + right.first + root->val, left.second + right.second + 1);

    }
    int averageOfSubtree(TreeNode* root) {
        pair<int, int> p = dfs(root);
        cout<<p.first<<" "<<p.second;
        return ans;
    }
};