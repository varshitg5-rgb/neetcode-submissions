class Solution {
public:
    int satisfy(vector<int> &piles, int k){
        int ans = 0;
        for(auto x:piles){
            ans = ans + (x/k);
            if(x%k!=0) ans++;
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int hi = INT_MIN;
        for(auto x : piles){
            hi = max(hi,x);
        }
        int ans = INT_MAX;
        while(l<=hi){
            int m = hi+(l-hi)/2;
            if(satisfy(piles,m)<=h){
                ans = min(ans,m);
                hi = m-1;
            }else{
                l = m+1;
            }
        }
        return ans;
    }
};
