/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        int ret = 0;
        isBST(root, ret);
        return ret;
    }
    
    vector<int> isBST(TreeNode* root, int& ret) {
        if (root == NULL) {
            return {INT_MAX, INT_MIN, 0};
        }
        
        vector<int> l = isBST(root->left, ret);
        vector<int> r = isBST(root->right, ret);
        if (l[2] == -1 || r[2] == -1) {
            return {INT_MIN, INT_MAX, -1};
        }
        
        // larger than largest on the left , and smaller the smallest on the right
        if (root->val > l[1] && root->val < r[0]) {
            int root_num = l[2] + r[2] + 1; 
            ret = max(ret, root_num);
            return {l[0] == INT_MAX ? root->val : l[0], r[1] == INT_MIN ? root->val : r[1], root_num};
        } else {
            return {INT_MIN, INT_MAX, -1};
        }
    }
};