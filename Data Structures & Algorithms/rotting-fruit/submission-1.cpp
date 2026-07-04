class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1) fresh++;
            }
        }
        if(fresh==0) return 0;
       
        int ans = -1;
        while(!q.empty()){
            int k = q.size();
            for(int i=0;i<k;i++){
                pair<int,int> p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                if(x+1<n && grid[x+1][y]==1){
                    grid[x+1][y] = 2;
                    fresh--;
                    q.push({x+1,y});
                }
                if(x-1>=0 && grid[x-1][y]==1){
                    grid[x-1][y] = 2;
                    fresh--;
                    q.push({x-1,y});
                }
                if(y+1<m && grid[x][y+1]==1){
                    grid[x][y+1] = 2;
                    fresh--;
                    q.push({x,y+1});
                }
                if(y-1>=0 && grid[x][y-1]==1){
                    grid[x][y-1] = 2;
                    fresh--;
                    q.push({x,y-1});
                }
            }
            ans++;
        }
        return (fresh==0)?ans:-1;

    }
};
