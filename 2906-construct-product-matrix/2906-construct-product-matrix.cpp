class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int MOD = 12345;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> p(n, vector<int>(m));
        long long s = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                p[i][j] = s;
                s = (s * (grid[i][j] % MOD)) % MOD;
            }
        }
        long long pr = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                p[i][j] = (p[i][j] * pr) % MOD;
                pr = (pr * (grid[i][j] % MOD)) % MOD;
            }
        }

        return p;
    }
};