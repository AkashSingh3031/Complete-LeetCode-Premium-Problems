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
    int countUnivalSubtrees(TreeNode* root) {
        int count = 0;
        countUnivalSubtreesRecursive(root, count);
        return count;
    }

    bool countUnivalSubtreesRecursive(TreeNode* root, int& count)
    {
        if(root == NULL) return true;

        auto isLeftUnival = countUnivalSubtreesRecursive(root->left, count);
        auto isRightUnival = countUnivalSubtreesRecursive(root->right, count);

        if(isLeftUnival && isRightUnival
            && ((root->left == NULL) || root->left->val == root->val)
            && ((root->right == NULL) || root->right->val == root->val)
        )
        {
            ++count;
            return true;
        }
        return false;
    }
};