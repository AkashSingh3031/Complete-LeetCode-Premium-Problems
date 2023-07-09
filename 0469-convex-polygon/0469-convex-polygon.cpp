class Solution {
public:
    bool isConvex(vector<vector<int>>& arr) {
        arr.push_back(arr[0]);
        arr.push_back(arr[1]);
        int n = arr.size(); 
        int cur = -2;
        for (int i = 0; i < n - 2; ++ i)
        {
            vector<int> v1 = {arr[i + 1][0] - arr[i][0], arr[i + 1][1] - arr[i][1]};
            vector<int> v2 = {arr[i + 2][0] - arr[i + 1][0], arr[i + 2][1] - arr[i + 1][1]};
            int val = v1[0] * v2[1] - v1[1] * v2[0];
            if (val == 0) continue;
            int sign = val > 0 ? 1 : -1;
        
            if (cur == -2 || cur == sign) 
                cur = sign;
            else
                return false;
        }
        return true;
    }
};