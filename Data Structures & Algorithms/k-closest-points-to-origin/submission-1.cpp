class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        unordered_map<int,vector<int>> u;
        priority_queue<int,vector<int>,greater<int>> pq;
        int i = 0;
        for(auto p : points){
            int x = p[0];
            int y = p[1];
            int dis = p[0]*p[0] + p[1]*p[1];
            if(u.find(dis)==u.end())  pq.push(dis);
            u[dis].push_back(i);
           
            i++;
        }

        vector<vector<int>> ans;
        while(ans.size()!=k){
            int d = pq.top();
            pq.pop();
            for(auto x : u[d]){
                if(ans.size()!=k){
                    ans.push_back(points[x]);
                }
            }
        }   
        return ans;
    }
};
