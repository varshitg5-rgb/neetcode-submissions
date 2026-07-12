class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dis(n,INT_MAX);
        dis[k-1] = 0;
        for(int i=0;i<n-1;i++){
            for(auto x : times){
                int u = x[0];
                int v = x[1];
                int d = x[2];
                if(dis[u-1]!=INT_MAX && dis[v-1]>dis[u-1]+d){
                    dis[v-1] = dis[u-1]+d;
                }
            }
        }

        int ans = INT_MIN;
        for(auto x : dis){
            ans = max(ans,x);
            if(ans==INT_MAX) return -1;
        }
        return ans;
    }
};
