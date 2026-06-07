class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_set<string> words(wordList.begin(),wordList.end());
        words.erase(beginWord);
        q.push({beginWord,1});
        while(!q.empty()) {
            int len = q.front().second;
            string currWord = q.front().first;
            q.pop();
            for(int i=0;i<currWord.size();i++) {
                for(char c='a';c<='z';c++) {
                    char originalChar = currWord[i];
                    currWord[i] = c;
                    if(words.find(currWord)!=words.end()) {
                        if(currWord==endWord) return len+1;
                        q.push({currWord,len+1});
                        words.erase(currWord);
                    }
                    currWord[i]=originalChar;
                }
            }
            
        }
        return 0;
    }
};