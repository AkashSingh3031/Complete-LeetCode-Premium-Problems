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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> output;
        if(!root){
            return output;
        }
        map<int, vector<int>> m;
        queue<pair<int, TreeNode*>> q;
        q.push(make_pair(0,root));
        while(!q.empty()){
            int size = q.size();
            for(int i = 0;  i < size; i++){
                TreeNode* t = q.front().second;
                int tmp = q.front().first;
                q.pop();
                m[tmp].push_back(t->val);
                if(t->left){
                    q.push(make_pair(tmp - 1, t->left));
                }
                if(t->right){
                    q.push(make_pair(tmp + 1, t->right));

                }
            }
        }
        for(auto& v : m){
            output.push_back(v.second);
        }
        return output;

    }
};