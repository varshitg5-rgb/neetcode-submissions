class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n);
        if(s[0]=='0') return 0;
        dp[0] = 1;
        for(int i=1;i<n;i++){
            if(s[i-1]=='1' || (s[i-1]=='2' && (s[i]!='9'&& s[i]!='8' && s[i]!='7'))){
                dp[i] = (i!=1)?dp[i-2]:1;
            }
            if(s[i]!='0') dp[i] += dp[i-1];

            if(dp[i]==0) return 0;
        }
        return dp[n-1];
    }
};
