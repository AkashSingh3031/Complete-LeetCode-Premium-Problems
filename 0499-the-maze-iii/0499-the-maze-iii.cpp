class Solution {
public:
    string roll(vector<vector<int>>& maze, int rowBall, int colBall, const vector<int>& hole, int d_row, int d_col, int steps, const string& path, pair<string, int>& res)
    {
        if (steps < res.second) {
            if (d_row != 0 || d_col != 0) {
                while ((rowBall + d_row) >= 0 && (colBall + d_col) >= 0 && (rowBall + d_row) <  maze.size() 
                    && (colBall + d_col) < maze[0].size() && maze[rowBall + d_row][colBall + d_col] != 1) 
                {
                    rowBall += d_row;
                    colBall += d_col;
                    ++steps;
                    if (rowBall == hole[0] && colBall == hole[1] && steps < res.second) res = {path, steps};
                }
            }
            if (maze[rowBall][colBall] == 0 || steps + 2 < maze[rowBall][colBall]) {
                maze[rowBall][colBall] = steps + 2;
                if (d_row == 0) roll(maze, rowBall, colBall, hole, 1, 0, steps, path + "d", res);
                if (d_col == 0) roll(maze, rowBall, colBall, hole, 0, -1, steps, path + "l", res);
                if (d_col == 0) roll(maze, rowBall, colBall, hole, 0, 1, steps, path + "r", res);
                if (d_row == 0) roll(maze, rowBall, colBall, hole, -1, 0, steps, path + "u", res);
            }
        }
        return res.first;
    }
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) 
    {
        return roll(maze, ball[0], ball[1], hole, 0, 0, 0, "", pair<string, int>() = {"impossible", INT_MAX});
    }
};