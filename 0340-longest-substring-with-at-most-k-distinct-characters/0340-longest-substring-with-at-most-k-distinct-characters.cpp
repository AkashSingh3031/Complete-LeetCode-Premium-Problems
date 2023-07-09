class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> ctr;
        int j = -1, maxlen = 0;
        for (int i=0; i<s.size(); ++i) {
            ++ctr[s[i]];
            while (ctr.size() > k)
                if (--ctr[s[++j]] == 0)
                    ctr.erase(s[j]);
            maxlen = max(maxlen, i - j);
        }
        return maxlen;
    }
};