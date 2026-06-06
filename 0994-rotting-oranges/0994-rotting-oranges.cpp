class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int freshOrangesCount = 0;
        queue<pair<int,int>> q;
        for(int i =0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                if(grid[i][j]==2) {
                    q.push({i,j});
                }
                if(grid[i][j]==1) {
                    freshOrangesCount++;
                }
            }
        }
        int count=0;
        if(freshOrangesCount==0)return 0;
        while(!q.empty()) {
            count++;
            int len = q.size();
            // cout<<len<<endl;

            for(int i =0;i<len;i++) {
                pair<int,int> popVal = q.front();
                q.pop();
                int firstV = popVal.first;
                int secondV = popVal.second;
                vector<int> dx = {-1,0,1,0};
                vector<int> dy = {0,1,0,-1};
                for(int j =0;j<4;j++) {
                    int x=firstV + dx[j];
                    int y = secondV + dy[j];
                    if(x>=0&&x<m&&y>=0&&y<n && grid[x][y]==1) {
                        grid[x][y] = 2;
                        freshOrangesCount--;
                        q.push({x,y});
                    }
                }
            }
        }
        return freshOrangesCount==0? count-1: -1;
    }
};