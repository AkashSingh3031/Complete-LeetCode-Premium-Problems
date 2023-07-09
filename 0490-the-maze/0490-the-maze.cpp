class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        set<vector<int>> visited;
        return helper(maze, start, destination, visited);
    }
    bool helper(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination, set<vector<int>>& visited) {
        if(start == destination) return true;
        if(visited.find(start) != visited.end()) return false;
        visited.insert(start);
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(int i = 0; i < 4; i++) {
            vector<int> res = go2End(maze, start, dirs[i]);
            if(res == destination || helper(maze, res, destination, visited)) return true;
        }
        return false;
    }
    vector<int> go2End(vector<vector<int>>& maze, vector<int>& start, vector<int>& dir) {
        int i = start[0] + dir[0];
        int j = start[1] + dir[1];
        int m = maze.size();
        int n = maze[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n || maze[i][j] == 1) {
            return start;
        }
        vector<int> newStart = {i, j};
        return go2End(maze, newStart, dir);
    }
};