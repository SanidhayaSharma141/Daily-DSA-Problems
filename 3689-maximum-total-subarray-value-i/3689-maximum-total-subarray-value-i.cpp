class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxVal= *max_element(nums.begin(),nums.end());
        long long minVal = *min_element(nums.begin(),nums.end());

        return (maxVal-minVal)*k;
    }
};