class Solution {
public:
    void rec(vector<vector<int>>&ans, vector<int>&cur, int n, int first) {        
        if(n == 1) {            
            ans.push_back(cur);            
            return;
        }
        int start = cur.size() == 0 ? 2 : cur.back();     
        int j = first == 1 ? sqrt(n) : n;
        for(int i = start; i <= j; i++) {
            if(n%i == 0) {                
                cur.push_back(i);
                rec(ans, cur, n/i, 0);
                cur.pop_back();
            }
            
        }
    }
    vector<vector<int>> getFactors(int n) {   
        if(n == 1) return {};     
        vector<vector<int>>ans;
        vector<int>cur;
        rec(ans, cur, n, 1);
        return ans;       
    }
};