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
    int closestValue(TreeNode* root, double target) {
        int lower = INT_MIN , upper = INT_MAX;
        while(root){

            if(root->val == target) return target;

            if(root->val>target){
                upper = root->val;
                root = root->left;
            }else{
                lower = root->val;
                root = root->right;
            }
        }
        
        return upper-target < target - lower ? upper : lower;
    }
};