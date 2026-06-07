class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int minVal=prices[0];
        for(int i =0;i<prices.size();i++) {
            ans=max(ans, prices[i]-minVal);
            minVal=min(minVal, prices[i]);
        }
        return ans;
    }
};