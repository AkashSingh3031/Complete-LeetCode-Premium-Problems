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
    int traverse(TreeNode* node, vector<vector<int>>& ans, int depth) {
        // Check vector size by current traversing depth
        if (ans.size() <= depth) {
            ans.push_back(vector<int>());
        }
        // Not a valid node
        if (node == nullptr) {
            return 0;
        }
        // At leave node
        if (node->left == nullptr && node->right == nullptr) {
            ans[0].push_back(node->val);
            return 0;
        }
        // At branch node
        int index = max(traverse(node->left, ans, depth + 1), traverse(node->right, ans, depth + 1)) + 1;
        ans[index].push_back(node->val);
        // Return leave index
        return index;
    }

    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        traverse(root, ans, 0);
        return ans;
    }
};