class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        vector<vector<int>> dp(n);
        dp[0] = {nums[0],-1*nums[0]};
        for(int i=1;i<n;i++){
            for(auto x : dp[i-1]){
                dp[i].push_back(x+nums[i]);
                dp[i].push_back(x-nums[i]);
            }
        }
        int count = 0;
        for(auto y : dp[n-1]){
            if(y==target) count++;
        }
        return count;
    }
};
