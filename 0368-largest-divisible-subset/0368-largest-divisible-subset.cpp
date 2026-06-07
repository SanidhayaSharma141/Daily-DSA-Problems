class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> hash(n);
        vector<int> ans;
        int maxVal=0;
        for(int i=0;i<n;i++) {
            hash[i]=i;
        }
        
        for(int i =0;i<n;i++) {
            int lastVal=i;
            for(int j=0;j<i;j++) {
                if(nums[i]%nums[j]==0) {
                    // dp[i] = max(dp[i], dp[j]+1);
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j] + 1;
                        lastVal=j;
                    }
                }
            }
            hash[i]=lastVal;
        }
        for(int i =0;i<n;i++) {
            if(dp[i]>dp[maxVal]){
                maxVal=i;
            }
        }

        while(hash[maxVal]!=maxVal) {
            ans.push_back(nums[maxVal]);
            maxVal=hash[maxVal];
        }
        ans.push_back(nums[maxVal]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};