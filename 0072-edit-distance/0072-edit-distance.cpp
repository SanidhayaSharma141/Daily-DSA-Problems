class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m =word2.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,INT_MAX));
        dp[0][0]=0;
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=m;j++) {
                if(i==0&&j==0){
                    dp[0][0]=0;
                }
                else if(i==0) {
                    dp[i][j]=j;
                }
                else if(j==0) {
                    dp[i][j]=i;
                }
                else {
                if(i>0&&j>0&&word1[i-1]==word2[j-1]){
                    dp[i][j]= dp[i-1][j-1];
                }
                else {
                    dp[i][j] = min(1+dp[i-1][j],min(1+dp[i][j-1],1+dp[i-1][j-1]));
                }
                }
            }
        }
        return dp[n][m];
    }
};