class Solution {
public:
    vector<string> generatePossibleNextMoves(string curr) {
        vector<string> res;
        for (int i = 0; i < curr.size() - 1; i++) {
            if (curr[i] == '+' && curr[i+1] == '+') {
                curr[i] = curr[i+1] = '-';
                res.push_back(curr);
                curr[i] = curr[i+1] = '+';
            }
        }       
        return res;
    }
};