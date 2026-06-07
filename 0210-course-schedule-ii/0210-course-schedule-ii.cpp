class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        vector<int> ans;
        queue<int> q;
        for(auto &i: prerequisites) {
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }

        for(int i=0;i<numCourses;i++) {
            if(indegree[i]==0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            if(indegree[node]==0) {
                ans.push_back(node);
                for(auto &i: adj[node]) {
                    indegree[i]--;
                    if(indegree[i]==0) {
                        q.push(i);
                    }
                }
            }
        }
        if(ans.size()==numCourses) return ans;
        return {};
    }
};