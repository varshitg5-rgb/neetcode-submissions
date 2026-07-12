class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> graph;
       vector<int> indegree(numCourses);
        for(auto x : prerequisites){
            int u = x[0];
            int v = x[1];
            graph[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }

        int count = 0;
        vector<int> ans;
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            ans.push_back(x);
            count++;
            for(auto y : graph[x]){
                indegree[y]--;
                if(indegree[y]==0) q.push(y);
            }
        }

        if(count!=numCourses) return {};

        reverse(ans.begin(),ans.end());
        return ans;
    }
};
