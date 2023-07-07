class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int ind1 = -1, ind2 = -1;
        int n = wordsDict.size();
        int ans = n;
        for(int i = 0;i<n;i++) {
            if(word1 == wordsDict[i]) {
                ind1 = i;
            } else if(word2 == wordsDict[i]) {
                ind2 = i;
            }
            if(ind1 != -1 && ind2 != -1) {
                ans = min(ans, abs(ind1 - ind2));
            }
        }
        return ans;
    }
};