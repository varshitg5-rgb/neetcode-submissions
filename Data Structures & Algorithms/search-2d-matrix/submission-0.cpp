class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0;
        int h = n-1;
        while(l<=h){
            int mi = l + (h-l)/2;
            if(matrix[mi][0]<=target && matrix[mi][m-1]>=target){
                int nl = 0;
                int nh = m-1;
                while(nl<=nh){
                    int nmi = nl + (nh-nl)/2;
                    if(matrix[mi][nmi]==target) return true;
                    else if(matrix[mi][nmi]<target) nl= nmi+1;
                    else nh = nmi-1;
                }
                return false;
            }else if(matrix[mi][0]>target){
                h = mi-1;
            }else{
                l = mi+1;
            }
        }
        return false;
    }

};
