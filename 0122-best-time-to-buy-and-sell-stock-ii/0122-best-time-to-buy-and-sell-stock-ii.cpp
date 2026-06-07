class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prevBuy=-prices[0];
        int prevSell=0;
        for(int i =1;i<prices.size();i++) {
            int currBuy= max(-prices[i]+prevSell, prevBuy);
            int currSell=max(prices[i]+prevBuy,prevSell);
            prevBuy=currBuy;
            prevSell=currSell;
        }
        return prevSell;
    }
};