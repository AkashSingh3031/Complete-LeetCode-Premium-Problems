class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        if(seqs.empty()) return false;
        vector<int> pos(org.size()+1);
        for(int i=0;i<org.size();++i) pos[org[i]] = i;
        
        vector<char> flags(org.size()+1,0);
        int toMatch = org.size()-1;
        for(const auto& v : seqs) {
            for(int i=0;i<v.size();++i) {
                if(v[i] <=0 || v[i] >org.size())return false;
                if(i==0)continue;
                int x = v[i-1], y = v[i];
                if(pos[x] >= pos[y]) return false;
                if(flags[x] == 0 && pos[x]+1 == pos[y]) flags[x] = 1, --toMatch;
            }
        }
        return toMatch == 0;
    }
};