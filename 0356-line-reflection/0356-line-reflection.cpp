class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {

        int minX = INT_MAX;
        int maxX = INT_MIN;
        set<pair<int, int>> uniquePoints;

        for(vector<int> point: points) {

            int x = point[0];
            minX = min(minX, x);
            maxX = max(maxX, x);
            uniquePoints.insert({x, point[1]});
        }

        double middleX = (minX + maxX) * 1.0 / 2;

        for(vector<int> point: points) {
            
            int x = point[0];
            int y = point[1];

            if(x == middleX) continue;
            if(uniquePoints.find({2 * middleX - x, y}) == uniquePoints.end()) 
                return false;
        }

        return true;

    }
};