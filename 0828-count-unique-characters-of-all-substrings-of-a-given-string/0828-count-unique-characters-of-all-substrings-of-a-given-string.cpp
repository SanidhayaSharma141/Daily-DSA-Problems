class Solution {
public:
    int uniqueLetterString(string s) {
        int n=s.size();
        vector<int> left(n), right(n);

        vector<int> last(26,-1);

        for(int i=0;i<n;i++) {
            left[i]=last[s[i]-'A'];
            last[s[i]-'A']=i;
        }
        fill(last.begin(), last.end(), n);
        for(int i=n-1;i>=0;i--) {
            right[i]=last[s[i]-'A'];
            last[s[i]-'A']=i;
        }
        int ans=0;
        for(int i =0;i<n;i++) {
            ans+= (i-left[i])*(right[i]-i);
        }
        return ans;
    }
};