class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char,unordered_set<char>> g;
        unordered_map<char,int> ind;
        int l=0;
        for(auto&w:words) for(auto c:w) ind[c]=0;
        for(int i=0;i+1<words.size();i++){
            auto& w1=words[i];
            auto& w2=words[i+1];
            int l=min(w1.size(),w2.size());
            int j=0;
            for(;j<l;j++){
                if(w1[j]==w2[j]) continue;
                g[w1[j]].insert(w2[j]); break;
            }
            if(j==w2.size() and w2.size()<w1.size()) return "";
        }
        for(auto&[u,vs]:g) for(auto&v:vs){
            ind[v]++;
        }
        string result;
        queue<char> q;
        for(auto&[c,n]:ind){
            if(n) continue;
            q.push(c);
        }
        while(q.size()){
            char u=q.front();
            q.pop();
            result+=u;
            for(auto v:g[u]){
                if(--ind[v]==0){
                    q.push(v);
                }
            }
        }
        return result.size()==ind.size()?result:"";
    }
};