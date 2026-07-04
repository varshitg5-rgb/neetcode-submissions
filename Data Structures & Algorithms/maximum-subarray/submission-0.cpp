class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        int ans = INT_MIN;
        int cur = 0;
        for(auto x : nums){
            cur += x;
            total += x;
            ans = max(ans, max(cur,total));
            if(cur<0) cur = 0;
        }
        return ans;
    }
};
