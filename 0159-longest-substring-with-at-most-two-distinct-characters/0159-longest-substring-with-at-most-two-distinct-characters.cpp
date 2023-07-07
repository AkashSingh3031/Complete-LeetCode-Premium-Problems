class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if(s.empty()) 
            return 0;
        int dict[256]; 
        fill_n(dict,256,0);
        int start = 0, len = 1, count = 0;
        for(int i=0; i<s.length(); i++) {
            dict[s[i]]++;
            if(dict[s[i]] == 1) { // new char
                count++;
                while(count > 2) {
                    dict[s[start]]--;
                    if(dict[s[start]] == 0) count--; 
                    start++;
                }
            }
            if(i-start+1 > len) len = i-start+1;
        }
        return len;
    }
};