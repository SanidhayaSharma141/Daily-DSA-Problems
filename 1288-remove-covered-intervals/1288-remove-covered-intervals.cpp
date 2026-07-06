class Solution {
    static bool comp(vector<int>&a, vector<int>&b) {
        if(a[0]!=b[0]) {
            return a[0]<b[0];
        }
        else {
            return a[1] > b[1];
        }
    }
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),comp);
        int count=1;
        int cur1=intervals[0][0];
        int cur2= intervals[0][1];
        for(int i =1;i<intervals.size();i++) {
            if(intervals[i][0]>=cur1 &&intervals[i][1]<=cur2) {
                continue;
            }
            else{
                count++;
                cur1=intervals[i][0];
                cur2=intervals[i][1];
            }
        }

        return count;

    }
};