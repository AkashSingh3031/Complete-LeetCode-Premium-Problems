class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> result;
        int lhs = lower;
        int i = 0;
        while(lhs <= upper) {
            if(i == nums.size()) {
                result.push_back({lhs, upper});
                break;
            }
            int rhs = nums[i];
            if(lhs < rhs) {
                result.push_back({lhs, rhs-1});
            }
            lhs = rhs+1;
            ++i;
        }
        return result;
    }
};