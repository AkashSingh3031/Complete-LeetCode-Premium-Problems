class ValidWordAbbr {
private: 
    unordered_set<string>dict ;
    unordered_map<string, bool>abbrUnique ;
    
    string getAbbr(const string& s){
        int n = s.size() ;
        if(n < 2)
            return s ;
        return s[0] + to_string(n-2) + s[n-1] ;
    }
public:
    ValidWordAbbr(vector<string>& dictionary) {
        dict = unordered_set(dictionary.begin(), dictionary.end()) ;
        for(const auto& word : dict){
            const string& abbr = getAbbr(word) ;
            if(abbrUnique.count(abbr) == 0)
                abbrUnique[abbr] = true ;
            else
                abbrUnique[abbr] = false ;
        }
    }
    
    bool isUnique(string word) {
        string abbr = getAbbr(word) ;
        if(abbrUnique.count(abbr) == 0)
            return true ;
        else if(abbrUnique[abbr] && dict.count(word) )
            return true ;
        else
            return false ;
    }
};


/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */