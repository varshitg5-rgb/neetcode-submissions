class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        vector<int> dp(amount+1,INT_MAX);
        dp[0] = 0;
        for(auto x : coins){
            if(x==amount) return 1;
            if(x<amount){
                dp[x] = 1;
            }
        }

        for(int i=1;i<=amount;i++){
            for(auto x : coins){
                if(x<=i && dp[i-x]!=INT_MAX) dp[i] = min(dp[i],dp[i-x]+1);
            }
            
        }
        return (dp[amount]==INT_MAX)?-1:dp[amount];
    }
};
