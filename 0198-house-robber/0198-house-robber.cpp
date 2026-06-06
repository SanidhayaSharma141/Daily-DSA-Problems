class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> v(nums.size(),0);

        for(int i =0;i<nums.size();i++) {
            if(i==0){
                v[i] = nums[i];
            }
            else if(i==1) {
                v[i]= max(nums[i], nums[i-1]);
            }
            else v[i] = max(nums[i]+v[i-2],v[i-1]);
        }
        return v[nums.size()-1];
    }
};