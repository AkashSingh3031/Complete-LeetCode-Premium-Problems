class Solution {
    bool check(string &s, int l, int r, int period) {
        if ((r - l + 1) % period)
            return 0;
        for (int i = l + period; i <= r; i++)
            if (s[i] != s[i - period])
                return 0;
        return 1;
    }
public:
    string encode(string &s) {
        vector<vector<string>> res(s.size(), vector<string>(s.size()));

        for (int i = 0; i < s.size(); i++)
            res[i][i] = string(1, s[i]);

        for (int len = 2; len <= s.size(); len++) {
            for (int l = 0, r = len - 1; r < s.size(); l++, r++) {
                res[l][r] = s.substr(l, len);

                for (int period = 1; period * 2 <= (r - l + 1); period++) {
                    if (check(s, l, r, period)) {
                        string candidate = to_string(len / period) + "[" + res[l][l + period - 1] + "]";
                        if (res[l][r].size() > candidate.size())
                            res[l][r] = candidate;
                    }
                }
                for (int m = l; m < r; m++)
                    if (res[l][r].size() > res[l][m].size() + res[m + 1][r].size())
                        res[l][r] = res[l][m] + res[m + 1][r];
            }
        }
        return res[0][s.size() - 1];
    }
};