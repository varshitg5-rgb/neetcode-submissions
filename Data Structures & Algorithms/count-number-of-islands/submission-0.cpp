class Solution {
public:
    void dfs(int i, int j, vector<vector<char>> &grid){
        int n = grid.size();
        int m = grid[0].size();

        if(i+1<n){
            if(grid[i+1][j]=='1'){
                grid[i+1][j] = '2';
                dfs(i+1,j,grid);
            }
        }
        if(i-1>=0){
            if(grid[i-1][j]=='1'){
                grid[i-1][j] = '2';
                dfs(i-1,j,grid);
            }
        }
        if(j+1<m){
            if(grid[i][j+1]=='1'){
                grid[i][j+1] = '2';
                dfs(i,j+1,grid);
            }
        }
        if(j-1>=0){
            if(grid[i][j-1]=='1'){
                grid[i][j-1] = '2';
                dfs(i,j-1,grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans= 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    grid[i][j] = '2';
                    ans++;
                    dfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};
