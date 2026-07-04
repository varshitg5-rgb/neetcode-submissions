class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        int c = 0;
        while(!q.empty()){
            int k = q.size();
            for(int i=0;i<k;i++){
                pair<int,int> p = q.front();
                int x = p.first;
                int y = p.second;
                grid[x][y] = c;
                q.pop();
                if(x+1<n && grid[x+1][y]==INT_MAX){
                    grid[x+1][y] = INT_MIN;
                    q.push({x+1,y});
                }
                if(x-1>=0 && grid[x-1][y]==INT_MAX){
                    grid[x-1][y] = INT_MIN;
                    q.push({x-1,y});
                }
                if(y-1>=0 && grid[x][y-1]==INT_MAX){
                    grid[x][y-1] = INT_MIN;
                    q.push({x,y-1});
                }
                if(y+1<m && grid[x][y+1]==INT_MAX){
                    grid[x][y+1] = INT_MIN;
                    q.push({x,y+1});
                }
            }
            c++;
        }
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==INT_MAX){
                    grid[i][j] =-1;
                }
            }
        }
        return;
    }
};
