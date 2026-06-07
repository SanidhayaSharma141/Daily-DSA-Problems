class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev(n+1,0);
        for(int i=n-1;i>=0;i--) {
            vector<int> curr(n+1,0);
            for(int j=i-1;j>=-1;j--) {
                curr[j+1]=prev[j+1];
                if(j==-1||nums[i]>nums[j]) {
                    curr[j+1]=max(curr[j+1],1+ prev[i+1]);
                }
            }
            prev=curr;
        }
        return prev[0];
    }
};