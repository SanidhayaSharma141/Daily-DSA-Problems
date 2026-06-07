class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int nextBuy=0;
        int nextSell=0;
        for(int i =prices.size()-1;i>=0;i--) {
            nextBuy= max(-prices[i]+nextSell, nextBuy);
            nextSell=max(prices[i]+nextBuy, nextSell);
        }
        return nextBuy;
    }
};