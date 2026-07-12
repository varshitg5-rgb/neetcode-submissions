class Solution {
public:
    int help(vector<vector<int>> &points,int a, int b){
        vector<int> f = points[a];
        vector<int> s = points[b];
        return abs(f[0]-s[0])+abs(f[1]-s[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> visited(n,false);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0,-1});
        int ans = 0;
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            int dis = cur[0];
            int node = cur[1];
            int parent = cur[2];
            if(visited[node]==true) continue;
            ans += cur[0];
            visited[node] = true;
           

            for(int i=0;i<n;i++){
                if(i!=node && visited[i]==false){
                    int d = help(points,i,node);
                    pq.push({d,i,node});
                }
            }
        }
        return ans;
    }
};
