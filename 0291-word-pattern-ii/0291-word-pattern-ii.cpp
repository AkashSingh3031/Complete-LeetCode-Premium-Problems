class Solution {
    unordered_map<string,char>mymap2;
    unordered_map<char,string> mymap1;
public:
    bool wordPatternMatch(string pattern, string s) {

        if(pattern.size() == 0 && s.size() == 0)return true;
        else if(pattern.size() == 0 || s.size() == 0)return false;

        char p = pattern[0];
        pattern.erase(0,1);
        if(mymap1.find(p)!=mymap1.end()){
            string temp = mymap1[p];
            int pos = s.find(temp);
            if(pos!=0){
                return false;
            }
            s.erase(0,temp.size());
            if(wordPatternMatch(pattern,s))return true;
            else return false;

        }

        for(int i=1;i<=s.size();i++){// here i is not the index but
        // i is the length of the current substring which is going to be mapped
            string res = s.substr(0,i);//i is the length of the substring 
            if(mymap2.find(res)!=mymap2.end()){
                continue;
            }
            mymap2[res] = p;
            mymap1[p] = res;
            string s1 = s;
            s1.erase(0,i);
            if(wordPatternMatch(pattern,s1))return true;
            mymap1.erase(p);
            mymap2.erase(res);
        }
        return false;
    }
};