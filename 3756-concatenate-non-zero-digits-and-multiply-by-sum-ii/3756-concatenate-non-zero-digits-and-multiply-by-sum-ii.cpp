class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        long long MOD = 1e9 + 7;

        string fs = ""; 
        vector<int> pii(n); 
        
        int current_idx = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                fs += s[i];
                pii[i] = current_idx;
                current_idx++;
            } else {
                pii[i] = current_idx; 
            }
        }

        int m = fs.length();
        if (m == 0) {
            return vector<int>(queries.size(), 0);
        }

        vector<long long> power10(m + 1, 1);
        for (int i = 1; i <= m; i++) {
            power10[i] = (power10[i - 1] * 10) % MOD;
        }

        vector<long long> prefSum(m + 1, 0);
        vector<long long> prefVal(m + 1, 0);

        for (int i = 0; i < m; i++) {
            int digit = fs[i] - '0';
            prefSum[i + 1] = (prefSum[i] + digit) % MOD;
            prefVal[i + 1] = (prefVal[i] * 10 + digit) % MOD;
        }

        vector<int> ans;
        for (auto& q : queries) {
            int original_L = q[0];
            int original_R = q[1];

            int L = pii[original_L];
            int R = (original_R + 1 < n) ? pii[original_R + 1] - 1 : m - 1;

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            long long sum = (prefSum[R + 1] - prefSum[L] + MOD) % MOD;
            long long x = (prefVal[R + 1] - (prefVal[L] * power10[R - L + 1]) % MOD + MOD) % MOD;

            long long result = (sum * x) % MOD;
            ans.push_back(result);
        }

        return ans;
    }
};