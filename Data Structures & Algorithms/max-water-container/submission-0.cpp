class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        int st = 0;
        int ed = n-1;
        while(st<ed){
            ans = max(ans,min(heights[st],heights[ed])*(ed-st));
            if(heights[st]<heights[ed]){
                st++;
            }else{
                ed--;
            }
        }
        return ans;
    }
};
