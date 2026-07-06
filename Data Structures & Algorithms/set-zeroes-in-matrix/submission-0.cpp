class Solution {
public:
    void found(int i, int j, vector<vector<int>> &matrix){
        int n = matrix.size();
        int m = matrix[0].size();
        for(int k=0;k<m;k++){
            matrix[i][k] = 0;
        }
        for(int k=0;k<n;k++){
            matrix[k][j] = 0;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    v.push_back({i,j});
                    //found(i,j,matrix);
                }
            }
        }
        for(auto x : v){
            found(x.first,x.second,matrix);
        }
    }
};
