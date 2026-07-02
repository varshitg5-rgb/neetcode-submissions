class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans =0;
        unordered_set<int> u;
        for(auto x : nums) u.insert(x);
        for(auto x : nums){
            if(u.find(x-1)==u.end()){
                int cur = 1;
                while(u.find(x+cur)!=u.end()){
                    cur++;
                }
                ans = max(ans,cur);
            }
        }
        return ans;

    }
};
