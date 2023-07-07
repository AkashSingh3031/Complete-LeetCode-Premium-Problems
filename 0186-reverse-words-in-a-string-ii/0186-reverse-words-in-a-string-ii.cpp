class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        for (int i = 0, j = 0; i < s.size(); i = j + 1) {
            for (j = i; j < s.size() && !isblank(s[j]); ++j);
            reverse(s.begin()+i, s.begin()+j);
        }
    }
};