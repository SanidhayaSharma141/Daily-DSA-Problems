#include<bits/stdc++.h>
class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0) {
            return 0;
        }
        string num= to_string(n);
        string s="";
        int sum=0;
        for(int i=0;i<num.size();i++) {
            if(num[i]!='0'){
                s.push_back(num[i]);
                sum+= num[i]-'0';
            }
        }
        int nu=stoi(s);
        return (long long)sum*(long long)nu;
    }
};