class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int currentElement = nums[0];
        int count = 1;
        for(int i =1;i<n;i++) {
            if(count == 0) {
                currentElement=nums[i];
                count++;
                continue;
            }
            if(nums[i]==currentElement) {
                count++;
            }
            else {
                count --;
            }
        }
        // for(int i = 0;i<n;i++){
        //     if(nums[i]==currentElement) {
        //         count++;
        //     }
        // }
        return currentElement;
    }
};