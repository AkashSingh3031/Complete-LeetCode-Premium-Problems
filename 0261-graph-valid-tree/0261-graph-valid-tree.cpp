class Solution {
private:
    class UnionFind {
    public:
        vector<int> root, size;
        
        UnionFind(int n) {
            root.resize(n), size.resize(n , 1);
            for(int i = 0; i < n; i++)
                root[i] = i;
        }
        
        int getRoot(int idx) {
            while(idx != root[idx]) {
                root[idx] = root[root[idx]];
                idx = root[idx];
            }
            return idx;
        }
        
        bool Union(int a, int b) {
            int rootA = getRoot(a);
            int rootB = getRoot(b);
            
            if(rootA != rootB) {
                if(size[rootA] > size[rootB]) {
                    size[rootA] += size[rootB];
                    root[rootB] = rootA;
                }
                else {
                    size[rootB] += size[rootA];
                    root[rootA] = rootB;
                }
                return true;
            }
            return false;
        }
    };
    
public:
    // Topological sort to detect cycle
    bool topoDfs(int curr, int parent, vector<vector<int>>& g, unordered_set<int>& visited,
                vector<bool>& rec_stack) {
        if(visited.count(curr))
            return false;
        
        // mark as visited
        visited.emplace(curr);
        // add to recursion stack
        rec_stack[curr] = true;
        
        for(auto neighbor: g[curr]) {
            // cycle is present if the current neighbor has an edge to another previously
            // seen node in the current path. It cannot be parent node as the edge is undirected
            // and hence the current node will have an edge to its parent
            if(rec_stack[neighbor] && parent != neighbor)
                return true;
            
            if(!visited.count(neighbor) && topoDfs(neighbor, curr, g, visited, rec_stack))
                return true;
        }
        // remove current from recursion stack
        rec_stack[curr] = false;
        return false;
    }
    
    // SOLUTION 1: Topological Sort using DFS
    // TC: O(V + E)
    // SC: O(V + E)
    bool dfsSol(vector<vector<int>>& g) {
        unordered_set<int> visited;
        
        for(int node = 0; node < g.size(); node++) {
            vector<bool> rec_stack(g.size(), false);
            // graph is disconnected
            if((!visited.empty() && visited.count(node) == 0))
                return false;
            
            // cycle is present
            if(topoDfs(node, -1, g, visited, rec_stack))
                return false;
        }
        return true;    
    }

    // SOLUTION 2: Union-Find
    // TC: O(ElogV)
    // SC: O(V)
    bool unionFindSol(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        
        // cycle present
        for(auto edge: edges)
            if(!uf.Union(edge[0], edge[1]))
                return false;
        
        // disconnected components
        int disconnected = 0;
        for(int i = 0; i < n; i++) {
            if(uf.root[i] == i)
                ++disconnected;
            if(disconnected > 1)
                return false;
        }
        
        return true;
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        // create the graph
        vector<vector<int>> g(n);
        
        for(auto edge: edges) {
            int src = edge[0], dst = edge[1];
            g[src].push_back(dst);
            g[dst].push_back(src);
        }
        
        // return dfsSol(g);
        return unionFindSol(n, edges);
    }
};