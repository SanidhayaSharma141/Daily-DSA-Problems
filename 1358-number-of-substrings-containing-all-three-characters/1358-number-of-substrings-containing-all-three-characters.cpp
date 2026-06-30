class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> vec(3,-1);
        int count=0;
        for(int i=0;i<s.size();i++){
            vec[s[i]-'a']=i;
            count+=1+min(vec[0],min(vec[1],vec[2]));
        }
        return count;
    }
};