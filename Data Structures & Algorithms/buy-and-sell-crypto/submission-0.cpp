class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        int maxsofar = prices[n-1];
        for(int i=n-1;i>=0;i--){
            maxsofar = max(maxsofar,prices[i]);
            ans = max(ans, maxsofar-prices[i]);
        }
        return ans;
    }
};
