class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n =graph.size();
        vector<vector<int>> rGraph(n);
        vector<int> ans;
        queue<int> q;
        vector<int> inDegree(n,0);
        for(int i =0;i<n;i++) {
            for(int j=0;j<graph[i].size();j++) {
                rGraph[graph[i][j]].push_back(i);
                inDegree[i]++;
            }
        }
        
        for(int i =0;i<n;i++) {
            if(inDegree[i]==0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int el= q.front();
            q.pop();
            ans.push_back(el);
            for(auto&i:rGraph[el]) {
                inDegree[i]--;

                if(inDegree[i]==0) {
                    q.push(i);
                }
            }
        }

        sort(ans.begin(),ans.end());
        return ans;

    }
};