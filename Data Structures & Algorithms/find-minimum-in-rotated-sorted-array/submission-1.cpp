class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        int ans = INT_MAX;
        while(lo<=hi){
            int m = lo+(hi-lo)/2;

            if(nums[m] <= nums[n-1]){
                ans = min(ans,nums[m]);
                hi = m-1;
            }else{
                ans = min(ans,nums[0]);
                lo = m+1;
            }
        }
        return ans;
    }
};
