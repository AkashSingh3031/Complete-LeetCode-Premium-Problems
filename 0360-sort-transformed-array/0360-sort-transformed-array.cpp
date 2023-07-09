class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        transform(nums.begin(), nums.end(), nums.begin(), [&](int& val) -> int {
            val = a * pow(val, 2) + b * val + c;
            return val;
        });

        sort(nums.begin(), nums.end());
        return nums;
    }
};