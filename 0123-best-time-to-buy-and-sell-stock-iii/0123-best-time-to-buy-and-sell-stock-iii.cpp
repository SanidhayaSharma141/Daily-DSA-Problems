class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> prev(4,0);

        for(int i = prices.size()-1;i>=0;i--) {
            vector<int> curr(4,0);
            for(int j =0;j<4;j++) {
                if(j%2==0){
                    curr[j] = max(-prices[i]+prev[j+1],prev[j]);
                }
                else{
                    if(j!=3)curr[j] = max(prices[i]+prev[j+1],prev[j]);
                    else{
                        curr[j]=max(prices[i],prev[j]);
                    }
                }
            }
            prev=curr;
        }
        return prev[0];
    }
};