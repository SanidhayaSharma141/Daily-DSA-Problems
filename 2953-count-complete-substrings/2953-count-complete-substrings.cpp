class Solution {
public:
    int countForBlock(const string& s, int k) {
        int n = s.size();
        int res = 0;

        for (int u = 1; u <= 26; ++u) {
            int window_len = u * k;
            if (window_len > n) break;

            vector<int> freq(26, 0);
            int count_with_k = 0;
            for (int i = 0; i < window_len; ++i) {
                int idx = s[i] - 'a';
                if (freq[idx] == k) count_with_k--;
                freq[idx]++;
                if (freq[idx] == k) count_with_k++;
            }
            if (count_with_k == u) res++;
            for (int i = window_len; i < n; ++i) {
                int in_idx = s[i] - 'a';
                if (freq[in_idx] == k) count_with_k--;
                freq[in_idx]++;
                if (freq[in_idx] == k) count_with_k++;

                int out_idx = s[i - window_len] - 'a';
                if (freq[out_idx] == k) count_with_k--;
                freq[out_idx]--;
                if (freq[out_idx] == k) count_with_k++;

                if (count_with_k == u) res++;
            }
        }
        return res;
    }

    int countCompleteSubstrings(string word, int k) {
        int n = word.size();
        int total_ans = 0;
        int start = 0;
        for (int i = 1; i <= n; ++i) {
            if (i == n || abs(word[i] - word[i - 1]) > 2) {
                string block = word.substr(start, i - start);
                total_ans += countForBlock(block, k);
                start = i;
            }
        }

        return total_ans;
    }
};