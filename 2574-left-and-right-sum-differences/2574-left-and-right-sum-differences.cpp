class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n,0);
        vector<int> rightSum(n,0);
        for(int i = 0;i<n;i++) {
            if(i!=0) leftSum[i]=leftSum[i-1]+nums[i-1];
            if(i!=0) rightSum[n-1-i]= rightSum[n-i] + nums[n-i];
        }
        vector<int> ans;
        for(int i =0;i<n;i++) {
            ans.push_back(abs(leftSum[i]-rightSum[i]));
        }
        return ans;
    }
};