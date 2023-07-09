class Solution {
public:
    int dfs(const vector<vector<int>>& adj, int n)
    {
        int count = 0;
        bool* visited = new bool[n];
        
        for (int i = 0; i < n; i++) 
            visited[i] = false;
        
        stack<int> stk;
        for (int node = 0; node < n; node++) 
        {
            if (!visited[node])
            {
                visited[node] = true;
                stk.push(node);
                count++;

                while (!stk.empty()) 
                {
                    int curr = stk.top();
                    stk.pop();
                    visited[curr] = true;
                    for (int index = 0; index < adj[curr].size(); index++) 
                    if (!visited[adj[curr][index]])
                        stk.push(adj[curr][index]);
                }
            }
        }
        return count;
    }

    int countComponents(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>> adj(n); 
        for (auto& edge: edges) 
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        return dfs(adj, n);
    }  
};