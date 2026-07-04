class Solution {
public:
    void dfs(unordered_map<int,vector<int>> &u, vector<bool> &visited, int idx){
        
        for(auto x : u[idx]){
            if(visited[x]==false){
                visited[x] =true;
                dfs(u,visited,x);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> u;
        for(auto x : edges){
            u[x[0]].push_back(x[1]);
            u[x[1]].push_back(x[0]);
        }
        vector<bool> visited(n,false);
        int count = 0;
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                count++; 
                visited[i] = true;
                dfs(u,visited,i);
            }
        }
        return count;
    }
};
