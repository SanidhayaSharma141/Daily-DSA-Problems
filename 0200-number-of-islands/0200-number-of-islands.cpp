class Solution {
public:
    void dfs( vector<vector<char>> & grid, int i, int j) {
        grid[i][j]='0';
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,-1,1};
        for(int l=0;l<4;l++) {
            int x = i+dx[l];
            int y = j + dy[l];
            if(x>=0&&x<grid.size()&&y>=0&&y<grid[0].size()&&grid[x][y]=='1') {
                dfs(grid,x,y);
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for( int j=0;j<n;j++) {
                if(grid[i][j]=='1') {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};