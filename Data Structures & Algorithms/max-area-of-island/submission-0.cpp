class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &grid, int& count){
        int n = grid.size();
        int m = grid[0].size();

        count++;
        if(i+1<n){
            if(grid[i+1][j]==1){
                grid[i+1][j] = 2;
                dfs(i+1,j,grid,count);
            }
        }
        if(i-1>=0){
            if(grid[i-1][j]==1){
                grid[i-1][j] = 2;
                dfs(i-1,j,grid,count);
            }
        }
        if(j+1<m){
            if(grid[i][j+1]==1){
                grid[i][j+1] = 2;
                dfs(i,j+1,grid,count);
            }
        }
        if(j-1>=0){
            if(grid[i][j-1]==1){
                grid[i][j-1] = 2;
                dfs(i,j-1,grid,count);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans= 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    grid[i][j] = 2;
                    int count = 0;
                    dfs(i,j,grid,count);
                    ans = max(ans,count);
                }
            }
        }
        return ans;
    }
};
