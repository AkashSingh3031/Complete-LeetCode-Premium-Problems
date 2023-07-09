class Solution {
public:
    int firstMissingNumber(unordered_set<int> lut) {
        int m = lut.size();
        for (int i = 0; i < m; ++i) {
            if (lut.count(i) == 0) return i;
        }
        return m;
    }

    bool canWin(string s) {
        int curlen = 0, maxlen = 0;
        vector<int> board_init_state;
        for (int i = 0; i < s.size(); ++i) {    
            if (s[i] == '+') curlen++;              // Find the length of all continuous '+' signs
            if (i+1 == s.size() || s[i] == '-') {
                if (curlen >= 2) board_init_state.push_back(curlen);    // only length >= 2 counts
                maxlen = max(maxlen, curlen);       // Also get the maximum continuous length
                curlen = 0;
            }
        }          // For instance ++--+--++++-+ will be represented as (2, 4)
        vector<int> g(maxlen+1, 0);    // Sprague-Grundy function of 0 ~ maxlen
        for (int len = 2; len <= maxlen; ++len) {
            unordered_set<int> gsub;    // the S-G value of all subgame states
            for (int len_first_game = 0; len_first_game < len/2; ++len_first_game) {
                int len_second_game = len - len_first_game - 2;
                // Theorem 2: g[game] = g[subgame1]^g[subgame2]^g[subgame3]...;
                gsub.insert(g[len_first_game] ^ g[len_second_game]);
            }
            g[len] = firstMissingNumber(gsub);
        }
        
        int g_final = 0;
        for (auto& s: board_init_state) g_final ^= g[s];
        return g_final != 0;    // Theorem 1: First player must win iff g(current_state) != 0
    }
};