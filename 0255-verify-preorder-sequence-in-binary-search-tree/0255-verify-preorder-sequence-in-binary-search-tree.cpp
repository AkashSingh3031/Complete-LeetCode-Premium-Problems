class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> stk;
        int lower_bound = INT_MIN;
        for(int i = 0; i < preorder.size(); i++){
            if(stk.empty() || preorder[i] < preorder[i - 1]){
                if(preorder[i] <= lower_bound) return false;
                stk.push(preorder[i]);
            }else{
                while(!stk.empty() && stk.top() < preorder[i]){
                    lower_bound = stk.top();
                    stk.pop();
                }
                stk.push(preorder[i]);
            }
        }
        
        return true;
    }
};