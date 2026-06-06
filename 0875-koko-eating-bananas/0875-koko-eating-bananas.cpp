class Solution {
public:

    long long eatBananas(vector<int>&piles, int k) {
        long long ans=0;
        for(int i =0;i<piles.size();i++) {
            ans+=ceil((double)piles[i]/(double)k);
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans=high;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(eatBananas(piles, mid)<=h) {
                ans=mid;
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return low;
    }
};