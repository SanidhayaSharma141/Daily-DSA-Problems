class Solution {

public:

    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans(nums.size());
        int lessVal = 0;
        int greaterVal = nums.size() - 1;
        for (int i = 0, j = nums.size() - 1; i < nums.size(); i++, j--) {
            if (nums[i] < pivot) {
                ans[lessVal] = nums[i];
                lessVal++;
            }
            if (nums[j] > pivot) {
                ans[greaterVal] = nums[j];
                greaterVal--;
            }
        }
        while (lessVal <= greaterVal) {
            ans[lessVal] = pivot;
            lessVal++;
        }
        return ans;
    }
};
        
