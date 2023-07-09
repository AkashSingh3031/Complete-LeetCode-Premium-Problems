class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> mp{{nums[0], 0}};
        int l = nums[0]==k?1:0;
        long casted_k = k;
        for(int i = 1; i < nums.size(); i++){
            nums[i] += nums[i-1];
            
            long d = nums[i] - casted_k;
            if(nums[i] == k) l = i+1;
            if(mp.count(d)) l = max(l, i-mp[d]);
            if(!mp.count(nums[i])) mp[nums[i]] = i;            
        }        
        return l;   
    }
};