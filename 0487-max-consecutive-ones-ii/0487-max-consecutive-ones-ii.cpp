class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ones = 0;
        int ones_and_zero = 0;
        int ret = 0;
        
        for (int num : nums) {
            if (num == 1) {
                ++ones;
                ++ones_and_zero;
            } else {
                ones_and_zero = ones + 1;
                ones = 0;
            }
            ret = max(ret, ones_and_zero);
        }
        return ret;
    }
};