class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size(), K = A[0].size(), n = B[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        
        unordered_map<int, vector<pair<int,int>>> map_a;
        unordered_map<int, vector<pair<int,int>>> map_b;
        
        for(int i = 0; i < m; ++i) 
            for(int j = 0; j < K; ++j) 
                if(A[i][j]) map_a[i].push_back({j, A[i][j]});

        for(int i = 0; i < K; ++i) 
            for(int j = 0; j < n; ++j) 
                if(B[i][j]) map_b[i].push_back({j, B[i][j]}); 
        
        for(int i = 0; i < m; ++i)
            for(auto& [k,a] : map_a[i])
                for(auto& [j,b] : map_b[k])
                    res[i][j] += a*b;
        
        return res;
    }
};