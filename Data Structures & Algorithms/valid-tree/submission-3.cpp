class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> u;
        for(auto x : edges){
            int a = x[0];
            int b = x[1];
            u[a].push_back(b);
            u[b].push_back(a);
        }

        //{node,parent}
        queue<pair<int,int>> q;
        q.push({0,-1});
        vector<bool> visited(n,false);
        int count = 0;
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            int node = cur.first;
            int parent = cur.second;
            count++;
            visited[node] = true;
            for(auto x : u[node]){
                if(visited[x]==true && x!=parent) return false;
                if(!visited[x]) q.push({x,node});
            }

        }
        return (count==n);
    }
};
