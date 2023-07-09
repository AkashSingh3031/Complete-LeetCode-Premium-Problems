class Solution {
public:
    int setcnt;
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        setcnt = 0;
        vector<int> rep;
        vector<vector<int>> memo(m, vector<int>(n, -1));
        vector<int> result;
        for (vector<int> &pos : positions) {
            int i = pos[0], j = pos[1];
            if (memo[i][j] != -1) { result.push_back(setcnt); continue; }
            createSet(rep);
            memo[i][j] = rep.back();
            if (i > 0 && memo[i - 1][j] != -1) {
                uNION(rep, memo[i - 1][j], memo[i][j]);
            }
            if (i < (int)memo.size() - 1 && memo[i + 1][j] != -1) {
                uNION(rep, memo[i + 1][j], memo[i][j]);
            }
            if (j > 0 && memo[i][j - 1] != -1) {
                uNION(rep, memo[i][j - 1], memo[i][j]);
            }
            if (j < (int)memo[0].size() - 1 && memo[i][j + 1] != -1) {
                uNION(rep, memo[i][j + 1], memo[i][j]);
            }
            result.push_back(setcnt);
        }
        return result;
    }
    
    void printvec(vector<int> &rep) {
        for (auto ele : rep) {
            cout << ele << " ";
        }
        cout << endl;
    }

    void createSet(vector<int> &rep) {
        rep.push_back((int)rep.size());
        setcnt++;
    }

    void uNION(vector<int> &rep, int i, int j) {
        int jroot = find(rep, j), iroot = find(rep, i);
        if (jroot != iroot) {
            setcnt--;
        }
        rep[jroot] = iroot;
        
    }

    int find(vector<int> &rep, int i) {
        if (rep[i] == i) { return i; }
        rep[i] = find(rep, rep[i]);
        return rep[i];
    }

};