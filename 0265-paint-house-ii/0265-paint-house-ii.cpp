class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
    if(n==0) return 0;
    int k = costs[0].size();
    if(k==1) return costs[0][0];

    vector<int> dp(k, 0);
    int min1, min2;

    for(int i=0; i<n; ++i){
        int min1_old = (i==0)?0:min1;
        int min2_old = (i==0)?0:min2;
        min1 = INT_MAX;
        min2 = INT_MAX;
        for(int j=0; j<k; ++j){
            if(dp[j]!=min1_old || min1_old==min2_old){
                dp[j] = min1_old + costs[i][j];
            }else{//min1_old occurred when painting house i-1 with color j, so it cannot be added to dp[j]
                dp[j] = min2_old + costs[i][j];
            }

            if(min1<=dp[j]){
                min2 = min(min2, dp[j]);
            }else{
                min2 = min1;
                min1 = dp[j];
            }
        }
    }

    return min1;
    }
};