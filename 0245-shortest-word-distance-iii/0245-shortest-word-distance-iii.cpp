class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        long long dist = INT_MAX, i1 = dist, i2 = -dist;
        bool same = word1 == word2;
        for (int i=0; i<words.size(); i++) {
            if (words[i] == word1) {
                i1 = i;
                if (same)
                    swap(i1, i2);
            } else if (words[i] == word2) {
                i2 = i;
            }
            dist = min(dist, abs(i1 - i2));
        }
        return dist;
    }
};