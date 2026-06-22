class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> mp;

        for(int i =0;i<text.size();i++) 
        {
            mp[text[i]]++;
        }
        vector<char> chrs= {'b','a','l','o','n'};

        int curr=INT_MAX;
        for (int i =0;i<chrs.size();i++){
            if(chrs[i]=='l'||chrs[i]=='o'){
                mp[chrs[i]]/=2;
            }
            curr=min(curr,mp[chrs[i]]);
        }
        return curr;
    }
};