class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> ret;
        for (int i = 0; i <= s.size(); ++i)
            if (i == s.size() || s[i] == 'I')
            for (int j = i + 1, lenTmp = ret.size(); j > lenTmp; --j)
                ret.push_back(j);
        return ret;
    }
};