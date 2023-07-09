class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        const int row = grid.size();
        if (0 == row) return 0;
        const int col = grid[0].size();
        int total = 0;
        vector<int> posR, posC;
        for (int i = 0; i < row; ++i) 
        for (int j = 0; j < col; ++j) {
            if (grid[i][j] == 1) {
                posR.emplace_back(i);
                posC.emplace_back(j);
            }
        }
        int med1 = posR[posR.size() / 2];
        nth_element(posC.begin(), posC.begin() +  posC.size() / 2, posC.end());
        int med2 = posC[posC.size() / 2];
        for (auto pos1 : posR) total += abs(pos1 - med1);
        for (auto pos2 : posC) total += abs(pos2 - med2);
        return total;
    }
};