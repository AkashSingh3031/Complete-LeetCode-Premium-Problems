class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();
        int minDist = INT_MAX;

        vector<vector<int>> dists(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        vector<pair<int, int>> incr = { { 1,0 },{ 0,-1 },{ 0,1 },{ -1,0 } };

        q.push({ start[0], start[1] });
        dists[start[0]][start[1]] = 0;

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            int x = curr.first;
            int y = curr.second;
            int dist = dists[x][y];

            for (int k = 0; k < 4; ++k)
            {
                int i = x;
                int j = y;
                int step = 0;
                int d_i = incr[k].first;
                int d_j = incr[k].second;
                int tempMin = INT_MAX;

                while (i + d_i < m && i + d_i >= 0 && j + d_j >= 0 && j + d_j <n && maze[i + d_i][j + d_j] == 0)
                {
                    ++step;
                    i += incr[k].first;
                    j += incr[k].second;
                    
                }
                if (dists[i][j] == -1)
                {
                    dists[i][j] = dist + step;
                    q.push({ i,j });
                }
                else
                {
                    if (dists[i][j] > dist + step)
                    {
                        dists[i][j] = dist + step;
                        q.push({ i,j });
                    }
                }
            }
        }

        return dists[destination[0]][destination[1]];        
    }
};