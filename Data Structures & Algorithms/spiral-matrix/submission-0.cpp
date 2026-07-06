class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0;
        int col = 0;
        vector<int> ans;
        while(row<n && col<m){
            for(int i=col;i<m;i++){
                ans.push_back(matrix[row][i]);
            }
            row++;
            for(int i=row;i<n;i++){
                ans.push_back(matrix[i][m-1]);
            }
            m--;
            if(row<n){
                for(int i=m-1;i>=col;i--){
                    ans.push_back(matrix[n-1][i]);
                }
                n--;
            }
            if(col<m){
                for(int i=n-1;i>=row;i--){
                    ans.push_back(matrix[i][col]);
                }
                col++;
            }
        }
        return ans;
    }
};
