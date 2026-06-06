class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0;
        int high=m-1;
        while(low<=high) {
            int mid=low+(high-low)/2;
            int maxEln= 0;
            for(int i=0;i<n;i++) {
                if(mat[i][mid]>mat[maxEln][mid]){
                    maxEln=i;
                }
            }

            if((mid==0||mat[maxEln][mid]>mat[maxEln][mid-1])&&(mid==m-1||mat[maxEln][mid]>mat[maxEln][mid+1])) return {maxEln, mid};

            else if((mid!=0&&mat[maxEln][mid-1]>mat[maxEln][mid])){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return {};
    }
};